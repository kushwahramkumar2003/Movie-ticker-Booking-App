#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include <dir.h>
#include <errno.h>
#include "mtb.h"
int main()
{
    int result;
    result=mkdir("C:\\Movie Ticket Booking");
    if(result!=0 && errno!=17)
    {
        printf("Sorry! Application cannot run");
        printf("\nError Code:%d,",errno);
        perror("Reason:");
        return 1;
    }
    add_questions();
    set_master_admin();
    create_user("admin");
    int choice,resp;

    user *ur;
    while(1){
        choice=enter_login_choice();
        if(choice==0)
            break;
        switch(choice){
        case 1:
                ur=login("admin");
                if(ur==NULL){
                    break;
                }
                while(1){
                    choice=enter_choice(ur);
                if(choice==0)
                    break;
                switch(choice){
                case 1:
                    add_theater();
                    break;
                case 2:
                    show_theater();
                    break;
                case 3:
                      resp=delete_theater();
                      if(resp==1)
                      {
                          print_char(' ',80,25,BLACK);
                          print_title_in_middle("Theater details deleted successfully",25,LIGHTGREEN);

                      }
                      else
                      {
                          print_char(' ',80,25,BLACK);
                          print_title_in_middle("Could No Delete Theater",25,RED);

                      }
                      getch();
                      break;
                case 4:
                    add_movie();
                    break;
                case 5:
                    show_movie();
                    break;
                case 6:
                    resp=delete_movie();
                    if(resp==1)
                      {
                          print_char(' ',80,25,BLACK);
                          print_title_in_middle("Movie deleted successfully",25,LIGHTGREEN);

                      }
                      else
                      {
                          print_char(' ',80,25,BLACK);
                          print_title_in_middle("Could No Delete Movie",25,RED);

                      }
                      getch();
                    break;
                case 7:
                    change_contact_details(ur);
                    break;
                case 8:
                    resp=change_security_question(ur);
                    break;
                case 9:
                    change_password(ur);
                    break;
                case 10:
                     show_my_profile(ur);
                    break;
                default:
                    print_char(' ',80,25,BLACK);
                    print_title_in_middle("Invalid Choice! Try Again",25,RED);
                    getch();

                }
                }


        case 2:

                ur=login("user");
                if(ur==NULL)
                {
                    break;
                }
                while(1)
                {
                    int temp=0;
                    choice=enter_choice(ur);
                    if(choice==0)
                        break;
                    switch(choice)
                    {
                        case 1:
                            show_movie();
                            break;
                        case 2:
                            booking(ur);
                            break;
                        case 3:
                            show_bookings_of_user(ur);
                            break;
                        case 4:
                            cancel_booking_of_user(ur);
                            break;
                        case 5:
                            change_contact_details(ur);
                            break;
                        case 6:
                             change_security_question(ur);
                            break;
                        case 7:
                            change_password(ur);
                            break;
                        case 8:
                            show_my_profile(ur);
                            break;
                        case 9:

                            delete_my_account(ur);
                            getch();
                            temp=1;
                            break;

                    }
                    if(temp==1)
                        break;
                }
            break;
        case 3:
                create_user("user");
                continue;

        default:
            print_char(' ',80,25,BLACK);
            print_title_in_middle("Invalid Choice! Try Again",25,RED);
            getch();
        }

    }

    return 0;
}

