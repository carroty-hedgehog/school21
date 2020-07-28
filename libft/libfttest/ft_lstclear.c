#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)		
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;				//сохраняем ссылку на 0
		ft_lstdelone(*lst, del);		//удаляем ячейку
		*lst = tmp;						//возвращаем ссылку на 0	
	}									//а как происходит смещение на следующий? тип нам приходит адрес 
											//указателя на элемент как происходит удаление и смещение и сохранения 0?
										
}