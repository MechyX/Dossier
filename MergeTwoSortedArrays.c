#include<stdio.h>

void main()
{
        int a[5]={1,2,3,4,5};
        int b[3]={1,5,7};
        int c[8];
        int i=0,j=0,k=0;
        while(i<5&&j<3)
        {
            if(a[i]<b[j])
                {
                    c[k]=a[i];
                    k++;
                    i++;
                }

            else if(a[i]>b[j])
                {
                    c[k]=b[j];
                    k++;
                    j++;

                }

            else{
                c[k]=a[i];
                i++;
                j++;
                k++;
            }
        }

        while(i<5)
            c[k++]=a[i++];
        while(j<3)
            c[k++]=b[j++];

        for(i=0;i<k;i++)
            printf("%d ",c[i]);
}
