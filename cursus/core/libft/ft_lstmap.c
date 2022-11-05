#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	last = head;
	while (lst->next != NULL)
	{
		tmp = ft_lstnew(f(lst->next->content));
		if (tmp == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		last->next = tmp;
		last = last->next;
		lst = lst->next;
	}
	return head;
}
