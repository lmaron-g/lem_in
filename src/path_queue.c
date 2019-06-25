#include "lem_in.h"

_Bool		if_q_empty(t_room *q, int id)
{
	while (q)
	{
		if (q->id == id)
			return (FALSE);
		q = q->next;
	}
	return (TRUE);
}

void		q_push(t_room *q, int new_id, int prev_id)
{
	while (q->next)
		q = q->next;
	q->next = init_queue(new_id, prev_id, q);
}

_Bool		queue_pop(t_room **q)
{
	t_room	*next_el;
	t_room	*prev_el;

	if (q && *q)
	{
		next_el = (*q)->next;
		prev_el = (*q)->prev;
		prev_el->next = next_el;
		next_el->prev = prev_el;
		free(*q);
		*q = prev_el;
		return (TRUE);
	}
	else
		return (FALSE);
}

t_room		*init_queue(int new_id, int prev_id, t_room *prev)
{
	t_room	*q;
	t_room	*buf;

	if (!(q = (t_room*)malloc(sizeof(t_room))))
	{
		while (prev)
		{
			buf = prev;
			prev = prev->prev;
			free(buf);
		}
		termination();
	}
	q->next = NULL;
	q->id = new_id;
	q->prev = prev;
	q->from = prev_id;
	return (q);
}
