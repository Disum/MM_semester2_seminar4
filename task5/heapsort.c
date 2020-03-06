#include "heapsort.h"
void swap(struct point *a, struct point *b);

/* Предполагается, что n>0, и по указателю a расположен массив из n элементов.
 * Турнирная сортировка или алгоритм heapsort.
 * */
void heapsort(struct point *a, int n, int (*p)(struct point, struct point))
{
	int k, parent, position, i, child_1, child_2, child, width, width_dynamic, num_position;
	struct point buffer;

	/* Рассматриваем бинарное дерево с корнем a[0], где для любого a[k] потомками являются a[2*k + 1] и a[2*k + 2].
	 * Первый этап алгорима: превратить дерево в дерево, в котором всякая цепочка от корня до любого конечного элемента упорядочена по убыванию.
	 * */
	for( k = 1; k<n; k++ )
	{
		// Поиск позиции, на которую должен перейти a[k]
		for( position = k; position>0; position = parent )
		{
			parent = (int)( (position - 1)/2 );// Индекс родителя a[position]

			if( p(a[parent],a[k])>-1 )
				break;
		}

		buffer = a[k];
		for( i = k; i!=position; i = parent )
		{
			parent = (int)( (i - 1)/2 );
			a[i] = a[parent];
		}
		a[position] = buffer;
	}
	// Первый этап закончен. В a[0] находится максимальный элемент.

	/* Второй этап: для всех k = n - 1, .., 1: поменять местами a[0] и a[k], и в массиве первых k элементов массива a восстанавливаем структуру:
	 * всякая цепочка от корня до любого конечного элемента упорядочена по убыванию. */
	for( k = n - 1; k>0; k-- )
	{
		swap(a, a + k);

		child_1 = 1;
		child_2 = 2;
		// Поиск позиции, на которую должен перейти a[0] в массиве a длины k
		width = 1;// Число элементов на уровне дерева, на который будет переставлен a[0]
		for( position = 0; position<(k - 1); child_1 = 2*position + 1, child_2 = 2*position + 2)
		{// Много сравнений?
			if( child_2>k )
			{
				break;
			}

			if( (child_2==k) )
			{
				if( p(a[child_1], a[0])>0 )
				{
					position = child_1;
					width *= 2;
				}

				break;
			}

			if( p(a[child_1], a[0])>0 )
			{
				if( p(a[child_2], a[child_1])>0 )
				{
					position = child_2;
				} else
				{
					position = child_1;
				}

				width *= 2;
				continue;
			}

			if( p(a[child_2], a[0])>0 )
			{
				if( p(a[child_1], a[child_2])>0 )
				{
					position = child_1;
				} else
				{
					position = child_2;
				}

				width *= 2;
				continue;
			}

			break;// (a[position]>=a[child1]) && (a[position]>=a[child2])
		}

		buffer = a[0];
		width_dynamic = width;// Ширина уровня поддерева, в котором находится a[position]
		num_position = position - width + 1;// Номер позиции в уровне поддерева ширины width_dynamic;
		for( i = 0; i<position; i = child, width_dynamic = (int)(width_dynamic/2) )
		{
			if( num_position<(int)(width_dynamic/2) )
			{
				child = 2*i + 1;
			} else
			{
				child = 2*i + 2;
				num_position -= (int)(width_dynamic/2);
			}

			a[i] = a[child];
		}
		a[position] = buffer;
	}
}

void swap(struct point *a, struct point *b)
{
	struct point buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}
