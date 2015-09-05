#ifndef _ETA_VARLIB
#define _ETA_VARLIB
#define VARSTR_START_SIZE 15 /**< Default variable string start length */
#define VARSTR_REFILL_SIZE 5 /**< Default variable string refill length */
#define DPA_START_SIZE 25 /**< Default DPA start length */
#define DPA_REFILL_SIZE 10 /**< Default DPA refill length */

/**
 * \brief Dynamic Pointer Array: Used to store a set of pointers dynamically.
 */
typedef struct {
    void **keys; /**< Array of objects */
    int used; /**< Objects stored */
    int size; /**< Array size (in objects) */
} DPA;

extern DPA *DPA_init(void);
extern void *DPA_store(DPA *dpa, void *obj);
extern bool *DPA_rem(DPA *dpa, void *obj);
extern void DPA_free(DPA *dpa);


/**
 * \brief Expandable variable-length UCS-2 string.
 */
struct varstr {
    wchar_t *str; /**< string */
    int used; /**< wchar_ts used (not including null) */
    int size; /**< size of string (including null) */
};

extern struct varstr *varstr_init(void);
extern struct varstr *varstr_cat(struct varstr *vs, wchar_t *str);
extern struct varstr *varstr_ncat(struct varstr *vs, wchar_t *str, size_t count);
extern struct varstr *varstr_pushc(struct varstr *vs, wchar_t c);
extern wchar_t *varstr_pack(struct varstr *vs);
extern void varstr_free(struct varstr *vs);
#endif
