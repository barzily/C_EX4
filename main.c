#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    pnode tmp = NULL;
    pnode *head = &tmp;
    int from = 0;
    int src = 0;
    char user_c;
    char c;


    while (scanf("%c", &user_c) != EOF)
    {
 
        if(user_c == 'A')
        {
            freeGraph(head);
            scanf("%d", &from);
            *head =  creat_graph(from);
            
            scanf("%c", &c);
            
            while(scanf("%c", &c)!=0){
                if(c == 'n')
                {
                scanf("%d",&src);
                add_adge(head,src);
                }
                else
                {
                    break;
                }
            }

            
            user_c = c;
        }
        if(user_c == 'S')
        {
            int src = -1, dest = -1;
            scanf("%d %d", &src, &dest);
            int dij = shortest_Path(*head, src, dest);
            printf("Dijsktra shortest path: %d ",dij);
            printf("\n");
            continue;
        }
        if(user_c == 'D')
        {
            del_node(head);
            continue;
        }
        if(user_c == 'B')
        {
            add_node(head);
            continue;
        }


        if(user_c == 'T')
        {
            int tsp = TSP(*head);
            printf("TSP shortest path: %d ",tsp);
            printf("\n");
            continue;
        }
       
    
    }
    freeGraph(head);
}

