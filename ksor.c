
// int	count_r(t_node *stack, int index)
// {
// 	int	counter;

// 	counter = 0;
// 	while (stack && stack->s_index != index)
// 	{
// 		stack = stack->next;
// 		counter++;
// 	}
// 	return (counter);
// }


// void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
// {
// 	int	i;
// 	int	range;

// 	i = 0;
// 	range = ft_sqrt(length) * 14 / 10;
// 	while (stack_a->head)
// 	{
// 		if (stack_a->head->s_index <= i)
// 		{
// 			push(stack_b, stack_a, 'b', true);
// 			rotate(stack_b, 'b', true);
// 			i++;
// 		}
// 		else if (stack_a->head->s_index <= i + range)
// 		{
// 			push(stack_b, stack_a, 'b', true);
// 			i++;
// 		}
// 		else
// 			rotate(stack_a, 'a', true);
// 	}
// }

// void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
// {
// 	int	rb_count;
// 	int	rrb_count;

// 	while (length - 1 >= 0)
// 	{
// 		rb_count = count_r(stack_b->head, length - 1);
// 		rrb_count = (length + 3) - rb_count;
// 		if (rb_count <= rrb_count)
// 		{
// 			while (stack_b->head->s_index != length - 1)
// 				rotate(stack_b, 'b', true);
// 			push(stack_a, stack_b, 'a', true);
// 			length--;
// 		}
// 		else
// 		{
// 			while (stack_b->head->s_index != length - 1)
// 				reverse_rotate(stack_b, 'b', true);
// 			push(stack_a, stack_b, 'a', true);
// 			length--;
// 		}
// 	}
// }





// /////// my ksort //////////////////


// void	ksort_part_one(t_stack **stack_a, t_stack **stack_b, int length)
// {
// 	int	i;
// 	int	range;

// 	i = 0;
// 	range = ft_sqrt(length) * 133 / 100;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->index <= i)
// 		{
// 			push_other_stack(stack_a, stack_b, 'b');
// 			i++;
// 		}
// 		else if ((*stack_a)->index <= i + range)
// 		{
// 			push_other_stack(stack_a, stack_b, 'b');
// 			i++;
// 			if (!((*stack_a)->index <= i + range))
// 				ft_rotate_double(stack_a, stack_b);
// 			else
// 				ft_rotate(stack_b, 'b');
// 		}
// 		else
// 			ft_rotate(stack_a, 'a');
// 	}
// }

// void	ksort_part_two(t_stack **stack_a, t_stack **stack_b, int length)
// {
// 	int	rb_count;
// 	int	rrb_count;

// 	while (length - 1 >= 0)
// 	{
// 		rb_count = count_r(*stack_b, length - 1);
// 		rrb_count = (length + 3) - rb_count;
// 		if (rb_count <= rrb_count)
// 		{
// 			while ((*stack_b)->index != length - 1)
// 				ft_rotate(stack_b, 'b');
// 			push_other_stack(stack_b, stack_a, 'a');
// 			length--;
// 		}
// 		else
// 		{
// 			while ((*stack_b)->index != length - 1)
// 				ft_rotate_reverse(stack_b, 'b');
// 			push_other_stack(stack_b, stack_a, 'a');
// 			length--;
// 		}
// 	}
// }
