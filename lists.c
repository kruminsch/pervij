#include "./include/my.h"

void show_list(um_t *ptr)
{
 um_t *tmp;
 tmp = ptr;
 while (tmp != NULL) {
	 printf("%u\n", tmp->num);
	 for(u_int32_t i = 0; i < tmp->len; ++i)
		 printf("%u", tmp->plates[i]);
	 write(1, "\n", 1);

	 //write(1, "\n", 1);
	 tmp = tmp->next;
 }
 return;
}   



int put_elem(um_t **list, u_int32_t num, u_int32_t nmemb)
{
//	nt put_trail_elem(list_t **ptr_num, int num)
//{
    um_t *new_um;
    um_t *last = *list;

    new_um = malloc(sizeof(*new_um));
    new_um->num = num;
    new_um->plates = calloc(nmemb, sizeof(u_int32_t));
    new_um->len = nmemb;
    new_um->next = NULL;
    if (*list == NULL) {
        *list = new_um;
        new_um->prev = NULL;
        return (0);
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_um;
    new_um->prev = last;
    return (0);
}



int main(int ac, char **av)
{
	um_t *list;
	list = NULL;

	for (u_int32_t i = 0; i < 3; ++i) 
		put_elem(&list, i, i + 12);
        show_list(list);	


}
