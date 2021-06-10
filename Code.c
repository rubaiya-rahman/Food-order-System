#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void insertfirst(int num, char foodname[25], int quantity, float price);
void insertend(int num, char foodname[25], int quantity, float price);
void foodlist();
void updatefood();
void admin_updatefood();
void main_menu();
int main_menu_choice();
float food_choice();
void confirmm();
void payment();
void admin_choice();
void deletefood(int fd);
struct node
{
    int num;
    char foodname[50];
    int quantity;
    float price;
    struct node *next;
};
struct node *head;
int fdquantity,food,card_no[100],order=0,total_order[100],c_order=0,total_quantity[100];
float total_money=0,bill,card_money[100],money[100];
int main()
{
    printf("\n\t\t\tWELCOME TO THE DELICIOS FOOD WORLD\n\n");
    insertfirst(1,"Burger   ",23,120.23);
	insertend(2,"Pizza    ",13,200.67);
	insertend(3,"Hot Cake ",8,720.83);
	insertend(4,"Coffee   ",46,70.23);
	insertend(5,"Ice-Cream",46,70.23);
	insertend(6,"Sandwich ",34,60.23);
	insertend(7,"Grill    ",7,520.29);
	insertend(8,"Nun-Bread",121,35.13);
	insertend(9,"Cold Drinks",73,20.13);
main_menu_choice();

return 0;
}

void main_menu()
{
    printf("\n\t\t\t===> 1 Food List\n");
    printf("\n\t\t\t===> 2 Admin Panel\n");
    printf("\n\t\t\t===> 3 EXit\n");
}
int main_menu_choice()
{
int menu,passward;
main_menu();
   scanf("%d",&menu);

    if(menu>=1&&  menu<=3)
    {
        if( menu==1)
        {
            foodlist();
            confirmm();
        }
        else if(menu==2)
        {
            printf("Enter passward:");
            scanf("%d",&passward);
            if(passward==12345)
            {
                admin_choice();
            }
            else
                main_menu_choice();
        }
        else if( menu==3)
        {
            printf("\n\t\t\tThanks for using our system\n\n\n\n");
        }
        else
        {
        printf("\nEnter correct Choice\n");
               main_menu_choice();
    }
    }
    return menu;
}
void confirmm()
{
    food_choice();
        int confirm;
        printf("\n 1. Confirm to buy this");
        printf("\n 2. Food list");
        scanf("%d",&confirm);


if(confirm==1)
{
    payment:
    payment();
        printf("\n===>THANK YOU<===\n");
        printf("\n1.Wanna Buy Another Delicious Food\n");
        printf("\n2.Main Menu\n");
        while(1)
        {
            int af;
            scanf("%d",&af);
            if(af==1)
            {
                foodlist();
                food_choice();
                goto payment;

            }
            else if(af==2)
            {
                main_menu_choice();
                break;
            }
            else{
                printf("Enter Right Choice");
                continue;
            }
        }
}
        else if(confirm==2)
        {
            foodlist();
            confirmm();

        }
        else
        {
            main_menu_choice();
        }
    }
float food_choice()
{
        printf("\n\n place your Order:");
        scanf("%d",&food);
        if(food==0)
        {
          main_menu_choice();
          food_choice();

        }
        struct node *temp;
        temp=head;
        while(temp->num!=food)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("\n\nplease Enter correct choice from the list:\n ");
                foodlist();
                food_choice();
            }
        }
        printf("%d",temp->num);
              if(temp->num==food)
            {
            printf("\n\nEnter Food Quantity:");
            scanf("%d",&fdquantity);
            if(fdquantity==0)
            {
                printf("\nFood quantity can not be zero\n");
                printf("\nEnter Food Quantity:");
                     scanf("%d",&fdquantity);
            }
            else if(fdquantity>temp->quantity)
            {
                printf("\nOut of Stock\n");
                foodlist();
                food_choice();
            }

        }
        bill=temp->price*fdquantity;
    printf("\n Your BILL : %.2f TK",bill);

}
void payment()
{
    int pay;
    printf("\n1.Cash\n");
    printf("\n2.Credit Card\n");
    scanf("%d",&pay);
     struct node *temp=head;
     while(temp->num!=food)
        {
            temp=temp->next;
        }
    if(pay==1)
    {
        order++;
        total_order[order]=food;
        money[order]=temp->price*fdquantity;
        total_money=total_money+temp->price*fdquantity;
        total_quantity[order]=fdquantity;
    }
    //Credit Card
    else if(pay==2)
    {
        order++;
        int card_num,i=0;
        char pin;
        printf("\nEnter your Card No:\n");
        scanf("%d",&card_num);
        password:
        printf("\nEnter your Card Pin(We never save your Card pin)\n");
                  pin=getch();
                  while(pin!=' ')
                  {
                      printf("*");
                      i++;
                      pin=getch();
                  }
                  if(i<5)
                  {
                      goto password;
                  }
                  card_no[c_order]=card_num;
                   card_money[c_order]=temp->price*fdquantity;
                  c_order++;
                  total_order[order]=food;
                  total_quantity[order]=fdquantity;
        money[order]=temp->price*fdquantity;
        total_money=total_money+temp->price*fdquantity;


}
else
{
    payment();
}
updatefood();

}
void insertfirst(int num, char foodname[25], int quantity, float price)
{
  struct  node *cur;
    cur=(struct node*)malloc(sizeof (struct node));
    cur->next=NULL;
    cur->num=num;
    cur->price=price;
    cur->quantity=quantity;
    strcpy(cur->foodname,foodname);
    cur->next=head;
    head=cur;
}
void insertend( int num, char foodname[25], int quantity, float price)
{
      struct node *cur,*t=head;
    cur=(  struct node*)malloc(sizeof (  struct node));
    cur->next=NULL;
    cur->num=num;
    cur->price=price;
    cur->quantity=quantity;
    strcpy(cur->foodname,foodname);
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=cur;
    cur->next=NULL;

}
void deletefood(int fd)
{
    struct node *t=head,*t1;
    if(t->num!=fd)
    {
   while(t->num!=fd)
   {
       t1=t;
       t=t->next;
   }
   t1->next=t->next;
   free(t);
    }
    else
    {
        head=t->next;
        free(t);
    }

}
void foodlist()
{
      struct node *t=head;

    printf("| Food No | \tFood Name |  \t     Price   | \t   In Stock |");
    while(t!=NULL)
    {

   printf("\n|     %d      |    %s   |      %.2f     |      %d      | ",t->num,t->foodname,t->price,t->quantity);
        printf("\n\t");
        t=t->next;
    }
}
void updatefood()
{
    struct node *temp;
    temp=head;
    int uquantity;
    while(temp->num!=food)
    {
        temp=temp->next;
    }
uquantity=temp->quantity-fdquantity;
    temp->quantity=uquantity;
}
void admin_updatefood()
{
    int n,q,up;
    float p;
    struct node *t;
    t=head;
    printf("Input the serial of food you want to update:");
    scanf("%d",&n);
    while(t->num!=n)
    {
        t=t->next;
    }
    if(t->num==n)
    {
    printf("\n1.upadate Food Quantity:\n");
    printf("\n2.Update Price of food:");
    scanf("%d",&up);
    if(up==1)
    {
        printf("Input the total quantity of food:");
        scanf("%d",&q);
        t->quantity=q;
    }
    else if(up==2)
    {
        printf("Input the price of the food:");
        scanf("%f",&p);
        t->price=p;
    }
    }
    else
    {
        printf("Re Enter the food serial:");
        admin_updatefood();
    }


}
void admin_choice()
{
char name[50];
 int data,fq;
 float fp;
printf("\n You Are In Admin Panel\n");

                printf (" \n      1. Total Cash Today \n\n");
				printf("          2. View Card Pay \n\n");
				printf("          3.Add Food \n\n");
				printf("          4. Delete Food \n\n");
				printf("          5. Update Food List \n\n");
				printf("          6.View Food list \n");
				printf("          7. Instant Order Preview\n");
				printf("          0. Main Menu ");
int adminchoice,i;
scanf("%d",&adminchoice);
if(adminchoice==1)
{
    printf("Toatal Money = %.2f",total_money);
    admin_choice();
}
else if(adminchoice==2)
{
    if(c_order!=0)
    {
printf("Card No       |     Money$\n ");
for(i=0;i<c_order;i++)
printf("\n%d   |\t\t %.2f   \n",card_no[i],card_money[i]);
}
else if(order==0)
{
    printf("\nNo Card History\n");
}
admin_choice();
}
else if(adminchoice==3)
{
 printf("\nEnter Food Name:");
 scanf("%s",&name);
 fooddata:
     printf("\nEnter Food Serial:");
     scanf("%d",&data);
     struct node *temp;
     temp=head;
    while(temp->num!=data)
     {
         if(temp->next==NULL)
            break;
        temp=temp->next;
     }
     if(temp->num==data)
     {
      printf(" \nFood Serial Already Exist, Please Re-Enter  ");
      goto fooddata;
     }
     printf("\nEnter Food Price:");
     scanf("%f",&fp);
     printf("\nEnter Food Quantity:\n");
     scanf("%d",&fq);
     printf("Submitting Your Data....");
     insertend(data,name,fq,fp);
     printf("Adding Food Successful");
     admin_choice();
}
else if(adminchoice==4)
{
    int da;
   printf("Enter the serial you want to delete:");
   serial:
   scanf("%d",&da);
   struct node *t;
   t=head;
   while(t->num!=da)
   {
       t=t->next;
   }
   if(t->num==da)
    deletefood(da);
   else
   {
       printf("Enter correct serial:");
       goto serial;
   }
   admin_choice();
}
else if(adminchoice==5)
{
admin_updatefood();
admin_choice();
}
else if(adminchoice==6)
{
    foodlist();
    admin_choice();
}
else if(adminchoice==7)
{
    int or;
    struct node *temp;
   	printf("\n\tOrder No. FooD Name  Quantity   Price    In Stock |");
   	for(or=1;or<=order;or++)
        {
            temp=head;
            while(temp->num!=total_order[or])
            {
                temp=temp->next;
            }
            printf("\n\t%d  \t %s  \t %d  \t %.2f\t  %d   \n",or,temp->foodname,total_quantity[or],money[or],temp->quantity);
        }
    admin_choice();
}
else if(adminchoice==0)
{
    main_menu_choice();
}
else
{
    printf("\n Enter Right choice\n");
    admin_choice();
}
return;
}

