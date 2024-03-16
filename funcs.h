#include "math.h"

struct route
{
    char arxh[50],telos[50];
    int mikos,ypsos_anabasi,ypsos_katabasi,max_ypsos,min_ypsos;

};

void shortA(struct route A[],int n)
{
    struct route temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j].mikos<A[j+1].mikos)
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

struct route* readFromInput(int *n)
{
    struct route temp[500];
    scanf(" %d ",n);
    int i=0;
    struct route *w;

    for(int i=0;i<*n;i++)
    {
        fgets(temp[i].arxh,50,stdin);
        temp[i].arxh[strcspn(temp[i].arxh,"\n")]='\0';
        scanf(" %d ",&temp[i].mikos);
        scanf(" %d ",&temp[i].ypsos_anabasi);
        scanf(" %d ",&temp[i].ypsos_katabasi);
        scanf(" %d ",&temp[i].max_ypsos);
        scanf(" %d ",&temp[i].min_ypsos);
        fgets(temp[i].telos,50,stdin);
        temp[i].telos[strcspn(temp[i].telos,"\n")]='\0';
    }
    w=temp;
    return w;
}

void printData(struct route A[],int n)
{
    float est;

    shortA(A,n);

    for(int i=0;i<n;i++)
    {

        if(strcmp(A[i].arxh,A[i].telos)!=0)
        {

            printf("From %s to %s\n",A[i].arxh,A[i].telos);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");


            printf("From %s to %s\n",A[i].telos,A[i].arxh);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=(  A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
        else
        {
            printf("From %s to %s\n",A[i].arxh,A[i].telos);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }

    }
}

void findShort(struct route A[],int n)
{
    int L;
    float est;

    scanf("%d",&L);

    shortA(A,n);

    for(int i=0;i<n;i++)
    {
        if(A[i].mikos<=L)
        {
            if(strcmp(A[i].arxh,A[i].telos)!=0)
            {
                printf("From %s to %s\n",A[i].arxh,A[i].telos);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");

                printf("From %s to %s\n",A[i].telos,A[i].arxh);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");
            }
            else
            {
                printf("From %s to %s\n",A[i].arxh,A[i].telos);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");
            }
        }
    }
}

void findLocation(struct route A[],int n)
{
    char s[50];
    float est;

    fgets(s,50,stdin);
    s[strcspn(s,"\n")]='\0';

    shortA(A,n);

    for(int i=0;i<n;i++)
    {
        if(strcmp(s,A[i].telos)==0)
        {
            printf("From %s to %s\n",A[i].telos,A[i].arxh);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
        else if(strcmp(A[i].arxh,s)==0)
        {
            printf("From %s to %s\n",A[i].arxh,A[i].telos);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
    }
}

void findUpHill(struct route A[],int n)
{
    float est;

    shortA(A,n);

    for(int i=0;i<n;i++)
    {
        if(A[i].ypsos_anabasi>A[i].ypsos_katabasi)
        {
            printf("From %s to %s\n",A[i].arxh,A[i].telos);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
        else if(A[i].ypsos_anabasi<A[i].ypsos_katabasi)
        {
            printf("From %s to %s\n",A[i].telos,A[i].arxh);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
    }
}

void findDownHill(struct route A[],int n)
{
    float est;

    shortA(A,n);

    for(int i=0;i<n;i++)
    {
        if(A[i].ypsos_anabasi>A[i].ypsos_katabasi)
        {
            printf("From %s to %s\n",A[i].telos,A[i].arxh);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
        else if(A[i].ypsos_anabasi<A[i].ypsos_katabasi)
        {
            printf("From %s to %s\n",A[i].arxh,A[i].telos);
            printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
            printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

            est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
            if(  est -(int)est >= 0.5 )
                est+=1;

            printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
            printf("\n");
        }
    }
}

void findAltitude(struct route A[],int n)
{
    int min,max;
    float est;
    scanf("%d",&min);
    scanf("%d",&max);
    shortA(A,n);
    for(int i=0;i<n;i++)
    {
        if(A[i].max_ypsos<=max && A[i].min_ypsos>=min)
        {
            if(strcmp(A[i].arxh,A[i].telos)!=0)
            {
                printf("From %s to %s\n",A[i].arxh,A[i].telos);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");

                printf("From %s to %s\n",A[i].telos,A[i].arxh);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");
            }
            else
            {
                printf("From %s to %s\n",A[i].arxh,A[i].telos);
                printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                printf("\n");
            }
        }
    }
}

void findTimely(struct route A[],int n)
{
    int T;
    float estup,estdw;
    scanf("%d",&T);
    shortA(A,n);
    for(int i=0;i<n;i++)
    {
        if(strcmp(A[i].arxh,A[i].telos)!=0)
            {
                estup=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(estup<=T)
                {
                    printf("From %s to %s\n",A[i].arxh,A[i].telos);
                    printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                    printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                    if(  estup -(int)estup >= 0.5 )
                        estup+=1;

                    printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)estup);
                    printf("\n");
                }

                estdw=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
                if(estdw<=T)
                {
                    printf("From %s to %s\n",A[i].telos,A[i].arxh);
                    printf("Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
                    printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                    if(  estdw -(int)estdw >= 0.5 )
                        estdw+=1;

                    printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)estdw);
                    printf("\n");
                }
            }
            else
            {
                estdw=( A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
                if(estdw<=T)
                {
                    printf("From %s to %s\n",A[i].arxh,A[i].telos);
                    printf("Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                    printf("Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                    if(  estdw -(int)estdw >= 0.5 )
                        estdw+=1;

                    printf("Length %d, Estimated time %d min\n",A[i].mikos,(int)estdw);
                    printf("\n");
                }
            }
    }
}

struct route* readFromFile(int *n)
{
    struct route A[500];
    char s1[50],s[50],e[50];
    struct route *w;
    //char *s,*e;
    FILE *fp;

    fgets(s1,50,stdin);
    s1[strcspn(s1,"\n")]='\0';

    fp=fopen(s1,"r");


    if(fp!=NULL)
    {
        fscanf(fp," %d ",n);
        for(int i=0;i<*n;i++)
        {

            fgets(A[i].arxh,50,fp);
            A[i].arxh[strcspn(A[i].arxh,"\n")]='\0';

            fscanf(fp," %d ",&A[i].mikos);
            fscanf(fp," %d ",&A[i].ypsos_anabasi);
            fscanf(fp," %d ",&A[i].ypsos_katabasi);
            fscanf(fp," %d ",&A[i].max_ypsos);
            fscanf(fp," %d ",&A[i].min_ypsos);

            fgets(A[i].telos,50,fp);
            A[i].telos[strcspn(A[i].telos,"\n")]='\0';

            //s=malloc(50*sizeof(char));
            //fgets(s,50,fp);
            //s[strcspn(s,"\n")]='\0';
           // s=realloc(s,(strlen(s)+1)*(sizeof(char)));
           // strcpy(A[i].arxh,s);

           // e=malloc(50*sizeof(char));
           // fgets(e,50,fp);
           // e[strcspn(e,"\n")]='\0';
            //e=realloc(e,(strlen(e)+1)*(sizeof(char)));
           // strcpy(A[i].telos,e);

        }
        fclose(fp);
    }
    else
        printf("error read");
    w=A;
    return w;
}

void saveData(struct route A[],int n)
{
    char s1[50];
    FILE *fp;
    float est;

    shortA(A,n);

    fgets(s1,50,stdin);
    s1[strcspn(s1,"\n")]='\0';

    fp=fopen(s1,"w");
    if(fp!=NULL)
    {
        for(int i=0;i<n;i++)
        {
            if(strcmp(A[i].arxh,A[i].telos)!=0)
            {

                fprintf(fp,"From %s to %s\n",A[i].arxh,A[i].telos);
                fprintf(fp,"Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                fprintf(fp,"\n");


                fprintf(fp,"From %s to %s\n",A[i].telos,A[i].arxh);
                fprintf(fp,"Uphill %d, Downhill %d\n",A[i].ypsos_katabasi,A[i].ypsos_anabasi);
                fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=(  A[i].mikos /65.0 ) + ( A[i].ypsos_katabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                fprintf(fp,"\n");
            }
            else
            {
                fprintf(fp,"From %s to %s\n",A[i].arxh,A[i].telos);
                fprintf(fp,"Uphill %d, Downhill %d\n",A[i].ypsos_anabasi,A[i].ypsos_katabasi);
                fprintf(fp,"Max altitude %d, Min altitude %d\n",A[i].max_ypsos,A[i].min_ypsos);

                est=( A[i].mikos /65.0 ) + ( A[i].ypsos_anabasi /10.0 );
                if(  est -(int)est >= 0.5 )
                    est+=1;

                fprintf(fp,"Length %d, Estimated time %d min\n",A[i].mikos,(int)est);
                fprintf(fp,"\n");
            }

            /*fprintf(fp,"%s\n",A[i].arxh);
            fprintf(fp,"%d\n",A[i].mikos);
            fprintf(fp,"%d\n",A[i].ypsos_anabasi);
            fprintf(fp,"%d\n",A[i].ypsos_katabasi);
            fprintf(fp,"%d\n",A[i].max_ypsos);
            fprintf(fp,"%d\n",A[i].min_ypsos);
            fprintf(fp,"%s\n",A[i].telos);*/
        }

        fclose(fp);
    }
    else
        printf("error read");
}

