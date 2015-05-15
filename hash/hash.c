#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG(...) printf(__VA_ARGS__)

typedef struct _node {
    struct _node *next;
    int data;
} node_t, *pnode_t;

typedef struct _hash_tab {
    node_t *value[10];
} hash_tab_t, *phash_tab_t;

static phash_tab_t create_hash_table(void) {
    
    phash_tab_t hash = (phash_tab_t)malloc(sizeof(hash_tab_t));
    memset(hash, 0, sizeof(hash_tab_t));
    return hash;
}

static pnode_t find_data_in_hash(phash_tab_t hash, int data) {
    
    pnode_t p = NULL;
    
    if (NULL == hash) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return NULL;
    }
    
    if (NULL == (p = hash->value[data%10])) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return NULL;
    }
    
    while(p) {
        if (data == p->data) {
            return p;
        }
        p = p->next;
    }
    
    return NULL;
}

static unsigned char insert_data_into_hash_table(phash_tab_t hash, int data) {
    
    pnode_t p = NULL;
    
    if (NULL == hash) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    if (NULL == hash->value[data%10]) {
        p = (pnode_t)malloc(sizeof(node_t));
        memset(p, 0, sizeof(node_t));
        p->data = data;
        hash->value[data%10] = p;
        return 0;
    }
    
    if (NULL != find_data_in_hash(hash, data)) {
        return 1;
    }
    
    p = hash->value[data%10];
    while (NULL != p->next) {
        p = p->next;
    }
    
    p->next = (pnode_t)malloc(sizeof(node_t));
    p->next->data = data;
    p->next->next = NULL;
    
    return 0;
}

static unsigned char display_hash_table(phash_tab_t hash) {
    
    unsigned char i = 0;
    pnode_t p = NULL;
    
    if (NULL == hash) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    for (i = 0; i < 10; i++) {
        p = hash->value[i];
        LOG("hash[%d] : ", i);
        while (NULL != p) {
            LOG("%d ", p->data);
            p = p->next;
        }
        LOG("\n");
    }
    
    return 0;
}

static unsigned char delete_data_from_hash(phash_tab_t hash, int data) {
    
    pnode_t pcurr = NULL;
    pnode_t ppre = NULL;
    
    if (NULL == hash) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return 1;
    }
    
    if (NULL == (pcurr = hash->value[data%10])) {
        LOG("%s parament error in line : %d!\n", __FUNCTION__, __LINE__);
        return 1;
    }
    ppre = pcurr;
    while (pcurr) {
        if (data == pcurr->data) break;
        ppre = pcurr;
        pcurr = pcurr->next;
    }
    
    if (NULL == pcurr) {
        LOG("Not find valid data delete : %d\n", data);
        return 1;
    }
    
    ppre->next = pcurr->next;
    free(pcurr);
    
    return 0;
}

static void delete_hash_table(phash_tab_t hash) {

#if 1
    unsigned char i = 0;
    pnode_t *p = NULL;
    pnode_t tmp = NULL;
    
    for (i = 0; i < 10; i++) {
        p = &(hash->value[i]);
        while (NULL != *p) {
            tmp = *p;
            *p = (*p)->next;
            free(tmp);
        }
    }
#else
    unsigned char i = 0;
    pnode_t p = NULL;
    pnode_t tmp = NULL;
    
    for (i = 0; i < 10; i++) {
        p = hash->value[i];
        while (NULL != p) {
            tmp = p;
            p = p->next;
            free(tmp);
        }
    }
#endif
}

int main(int argc, char *argv[]) {
    
    unsigned char data = 0;
    phash_tab_t hash = create_hash_table();
    
    for (data = 0; data < 100; data++) {
        insert_data_into_hash_table(hash, data);
    }
    
    display_hash_table(hash);
    delete_data_from_hash(hash, 131);
    delete_data_from_hash(hash, 33);
    display_hash_table(hash);
    delete_hash_table(hash);
    display_hash_table(hash);
    return 0;
}




