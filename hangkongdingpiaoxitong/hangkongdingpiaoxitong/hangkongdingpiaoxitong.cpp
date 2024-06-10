#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>//获取getch();
#include <math.h>
#pragma warning(disable:4996);

typedef struct {
    char flight_no[10]; // 航班号
    char flight_num[10];//飞机号 
    char fly_day[10];//飞行日期 
    char departure_time[20]; // 起飞时间
    char arrival_time[20]; // 到达时间
    char departure_city[20]; // 起飞城市
    char arrival_city[20]; // 到达城市
    float price; // 票价
    int total_seats; // 总座位数
    int total_seats_1;//一等座位数 
    int total_seats_2;
    int total_seats_3;
    int booked_seats;//已定票数 
    int booked_seats_1; // 已订一等座位数
    int booked_seats_2;
    int booked_seats_3;
    
 //   int houbu_seats;//候补票数
} Flight;

typedef struct {
    char name[20]; // 姓名
    char id[20]; // 证件号
    int flight_index; // 航班信息在数组中的下标
    int seats_lv;//订票的等级 
    int num_tickets; // 订票总数量
    int num_tickets_1;//一等座订票数 
    int num_tickets_2;
    int num_tickets_3;
    int order_id; // 订单编号
  //  int houbu_id;//候补人数编号
} Order;





Flight flights[100]; // 存储航班信息的数组
int num_flights = 0; // 航班数量
Order orders[1000]; // 存储订票信息的数组
int num_orders = 0; // 订单数量
//int num_houbu = 0;//候补数量




void add_flight() {//录入航班信息 
    printf("<<<<<<<<<<<<<<<您正在录入航班信息>>>>>>>>>>>\n");
    Flight flight;
    printf("请输入航班号：");
    scanf("%s", flight.flight_no);
    printf("请输入飞机号：");
    scanf("%s", flight.flight_num);
    printf("请输入航班起飞日期(如23年12月11日)：");
    scanf("%s", flight.fly_day);
    printf("请输入起飞时间：");
    scanf("%s", flight.departure_time);
    printf("请输入到达时间：");
    scanf("%s", flight.arrival_time);
    printf("请输入起飞城市：");
    scanf("%s", flight.departure_city);
    printf("请输入到达城市：");
    scanf("%s", flight.arrival_city);
    printf("请输入票价：");
    scanf("%f", &flight.price);
    printf("请输入一等座位数：");
    scanf("%d", &flight.total_seats_1);
    printf("请输入二等座位数：");
    scanf("%d", &flight.total_seats_2);
    printf("请输入三等座位数：");
    scanf("%d", &flight.total_seats_3);
    flight.total_seats = flight.total_seats_1 + flight.total_seats_2 + flight.total_seats_3;
    printf("总座位数为：%d\n", flight.total_seats);
    flight.booked_seats = 0;
    flight.booked_seats_1 = 0;
    flight.booked_seats_2 = 0;
    flight.booked_seats_3 = 0;
    flights[num_flights++] = flight;
    printf("航班信息录入成功！\n");
}

void search_flight() {//查询航班信息 
    printf("<<<<<<<<<<<<<<<您正在使用查询航班信息功能>>>>>>>>>>>\n");
    char flight_no[10];
    printf("请输入要查询的航班号：");
    scanf("%s", flight_no);
    int i;
    for (i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].flight_no, flight_no) == 0) {
            printf("航班号：%s\n", flights[i].flight_no);
            printf("飞机号：%s\n", flights[i].flight_num);
            printf("航班起飞日期：%s\n", flights[i].fly_day);
            printf("起飞时间：%s\n", flights[i].departure_time);
            printf("到达时间：%s\n", flights[i].arrival_time);
            printf("起飞城市：%s\n", flights[i].departure_city);
            printf("到达城市：%s\n", flights[i].arrival_city);
            printf("票价：%.2f\n", flights[i].price);

            printf("总座位数：%d\n", flights[i].total_seats);
            printf("一等座位数：%d\n", flights[i].total_seats_1);
            printf("二等座位数：%d\n", flights[i].total_seats_2);
            printf("三等座位数：%d\n", flights[i].total_seats_3);

            printf("已订座位数：%d\n", flights[i].booked_seats);
            printf("已订一等座位数：%d\n", flights[i].booked_seats_1);
            printf("已订二等座位数：%d\n", flights[i].booked_seats_2);
            printf("已订三等座位数：%d\n", flights[i].booked_seats_3);

            printf("剩余座位数：%d\n", flights[i].total_seats - flights[i].booked_seats);
            printf("剩余一等座位数：%d\n", flights[i].total_seats_1 - flights[i].booked_seats_1);
            printf("剩余二等座位数：%d\n", flights[i].total_seats_2 - flights[i].booked_seats_2);
            printf("剩余三等座位数：%d\n", flights[i].total_seats_3 - flights[i].booked_seats_3);

            if (flights[i].booked_seats == flights[i].total_seats) {
                printf("该航班已满仓！\n");
            }
            break;
        }
    }
    if (i == num_flights) {
        printf("未找到该航班！\n");
    }
}

void search_flight_list() {
    printf("<<<<<<<<<<<<<<<您正在使用查询航线功能>>>>>>>>>>>\n");
    char departure_city[20], arrival_city[20];
    //    printf("请输入起飞城市：");
    //    scanf("%s", departure_city);
    printf("请输入到达城市：");
    scanf("%s", arrival_city);
    int i, count = 0;
    for (i = 0; i < num_flights; i++) {
        if (/*strcmp(flights[i].departure_city, departure_city) == 0 &&*/ strcmp(flights[i].arrival_city, arrival_city) == 0) {
            printf("航班号：%s，飞行日期：%s,票价：%.2f，一等票余票数：%d，二等票余数：%d,三等票余数：%d\n", flights[i].flight_no,flights[i].fly_day, flights[i].price, flights[i].total_seats_1 - flights[i].booked_seats_1, flights[i].total_seats_2 - flights[i].booked_seats_2, flights[i].total_seats_3 - flights[i].booked_seats_3);
            count++;
        }
    }
    if (count == 0) {
        printf("未找到符合条件的航班！\n");
    }
}

void book_ticket() {
    printf("<<<<<<<<<<<<<<<您正在办理订票业务>>>>>>>>>>>\n");
    char flight_no[10], name[20], id[20];
    int num_tickets=0, seats_lv, num_tickets_1=0, num_tickets_2=0, num_tickets_3=0,num_houbu=0,houbu_seats=0;
    printf("请输入要订票的航班号：");
    scanf("%s", flight_no);
    int i;
    Order order;
    for (i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].flight_no, flight_no) == 0) {
            if (flights[i].booked_seats == flights[i].total_seats) {
                printf("该航班已满仓！\n");
                return;
            }
            printf("请输入姓名：");
            scanf("%s", name);
            printf("请输入证件号：");
            scanf("%s", id);
 
            while (1) {
                int j=0;//控制结束循环
               // int k = 0;//控制是否候补
                printf("请输入订票的等级（1：为一等座，2：为二等座，3：为三等座，0：为退出购票）：");
                scanf("%d", &seats_lv);
                switch (seats_lv) {
                case 1:
                    printf("一等座余票为：%d\n", flights[i].total_seats_1 - flights[i].booked_seats_1);
                    printf("请输入订票数量：");
                    scanf("%d", &num_tickets_1);
                    if (num_tickets_1 > flights[i].total_seats_1 - flights[i].booked_seats_1) {
                        printf("余票不足！\n");
                        //printf("是否登记候补（1 为是 2 为否）");
                       //scanf("%d", &k);
                        //if (k == 1) {
                            //printf("请输入候补票数：");
                            //scanf("%d", &houbu_seats);
                            //order.houbu_id = num_houbu + 1;
                            //printf("候补编号为：%d", order.houbu_id);
                            //break;
                        //}else if(k==2) break;
                        break;
                    }
                    else {
                        
                        flights[i].booked_seats_1 += num_tickets_1;
                    }
                    break;
                case 2:                  
                    printf("二等座余票为：%d\n", flights[i].total_seats_2 - flights[i].booked_seats_2);
                    printf("请输入订票数量：");
                    scanf("%d", &num_tickets_2);
                    if (num_tickets_1 > flights[i].total_seats_2 - flights[i].booked_seats_2) {
                        printf("余票不足！\n");
                        break;
                    }
                    else {
                        
                        flights[i].booked_seats_2 += num_tickets_2;
                    }
                    break;
                case 3:                  
                    printf("三等座余票为：%d\n", flights[i].total_seats_3 - flights[i].booked_seats_3);
                    printf("请输入订票数量：");
                    scanf("%d", &num_tickets_3);
                    if (num_tickets_1 > flights[i].total_seats_3 - flights[i].booked_seats_3) {
                        printf("余票不足！\n");
                        break;
                    }
                    else {
                        
                        flights[i].booked_seats_3 += num_tickets_3;
                    }
                    break;
                case 0:
                    j = 1;
                    break;
                default:
                    printf("无效的操作！\n");
                    break;

                }
                if (j == 1) break;
                else continue;
            }


            strcpy(order.name, name);
            strcpy(order.id, id);
            order.flight_index = i;
            order.num_tickets = num_tickets;
            num_tickets = num_tickets_1 + num_tickets_2 + num_tickets_3;
            order.num_tickets_1 = num_tickets_1;
            order.num_tickets_2 = num_tickets_2;
            order.num_tickets_3 = num_tickets_3;
            order.order_id = num_orders + 1;
            orders[num_orders++] = order;
            flights[i].booked_seats = num_tickets;
            printf("以订总票数为：%d\n", flights[i].booked_seats);
            printf("订票成功！订单编号为%d\n", order.order_id);
            
            break;
        }
    }
    if (i == num_flights) {
        printf("未找到该航班！\n");
    }
}



void cancel_ticket() {
    printf("<<<<<<<<<<<<<<<您正在办理退票业务>>>>>>>>>>>\n");
    int order_id;
   
    printf("请输入要退票的订单编号：");
    scanf("%d", &order_id);
    int i;
    for (i = 0; i < num_orders; i++) {
        if (orders[i].order_id == order_id) {
            int flight_index = orders[i].flight_index;
            printf("数组下标:%d\n",orders[i].flight_index);
            printf("该订单以订总票数为:%d\n", orders[i].num_tickets = orders[i].num_tickets_1 + orders[i].num_tickets_2, +orders[i].num_tickets_3);
            while (1) {
                int a = 0;//控制结束循环
                int k;
                int b;//退票的张数
                printf("以订一，二，三等票数分别为：%d ，%d ,%d \n", orders[i].num_tickets_1, orders[i].num_tickets_2, orders[i].num_tickets_3);
                printf("请选择需要退的票（1：为一等座，2：为二等座，3：为三等座，0：为退出退票）：");
                scanf("%d", &k);
                switch (k) {                                      
                    case 1:
                        printf("以订一，二，三等票数分别为：%d ，%d ,%d \n", orders[i].num_tickets_1, orders[i].num_tickets_2, orders[i].num_tickets_3);
                        printf("要退多少张票:");
                        scanf("%d", &b);
                        if (b> orders[i].num_tickets_1) {
                            printf("您所退的票大于您已经购买的票请重新操作");
                        }
                        else {
                            flights[flight_index].booked_seats_1 -= b;
                            orders[i].num_tickets_1 -= b;
                            printf("退票成功！\n");
                        }
                        
                        break;
                    case 2:
                        printf("以订一，二，三等票数分别为：%d ，%d ,%d \n", orders[i].num_tickets_1, orders[i].num_tickets_2, orders[i].num_tickets_3);
                        printf("要退多少张票:");                        
                        scanf("%d", &b);
                        if (b > orders[i].num_tickets_2) {
                            printf("您所退的票大于您已经购买的票请重新操");
                        }
                        else {
                            flights[flight_index].booked_seats_2 -= b;
                            orders[i].num_tickets_2 -= b;
                            printf("退票成功！\n");
                        }
                        break;
                    case 3:
                        
                        printf("以订一，二，三等票数分别为：%d ，%d ,%d \n", orders[i].num_tickets_1, orders[i].num_tickets_2, orders[i].num_tickets_3);
                        printf("要退多少张票:");  
                        scanf("%d", &b);
                        if (b > orders[i].num_tickets_3) {
                            printf("您所退的票大于您已经购买的票请重新操");
                        }
                        else {
                            flights[flight_index].booked_seats_3 -= b;
                            orders[i].num_tickets_3 -= b;
                            printf("退票成功！\n");
                        }
                        break;
                    case 0:
                        a = 1;
                        break; 
                    default:
                        printf("无效的操作！\n");
                        break;
                }
               // printf(" 1:%d\n", flights[flight_index].booked_seats_1);
               // printf(" 2:%d\n", flights[flight_index].booked_seats_2);
               // printf(" 3:%d\n", flights[flight_index].booked_seats_3);
                flights[flight_index].booked_seats = flights[flight_index].booked_seats_1 + flights[flight_index].booked_seats_2 + flights[flight_index].booked_seats_3;
                if (a == 1)break;
                else continue;
            }

                      
            printf("该订单以订总票数为：%d\n", orders[i].num_tickets= orders[i].num_tickets_1+ orders[i].num_tickets_2,+orders[i].num_tickets_3);
           // printf("数组下标:%d\n", orders[i].flight_index);
            if (orders[i].num_tickets == 0) {
                int j;
                for (j = i; j < num_orders - 1; j++) {
                   orders[j] = orders[j + 1];
                }
                num_orders--;              
            }
            
            break;
        }
    }
    if (i == num_orders) {
        printf("未找到该订单！\n");
    }
}

void modify_flight() {
    char flight_no[10];
    printf("请输入要修改的航班号：");
    scanf("%s", flight_no);
    int i;
    for (i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].flight_no, flight_no) == 0) {
            printf("请输入输入的飞机号：");
            scanf("%s", flights[i].flight_num);
            printf("请输入新的航班起飞日期：");
            scanf("%s", flights[i].fly_day);
            printf("请输入新的起飞时间：");
            scanf("%s", flights[i].departure_time);
            printf("请输入新的到达时间：");
            scanf("%s", flights[i].arrival_time);
            printf("请输入新的起飞城市：");
            scanf("%s", flights[i].departure_city);
            printf("请输入新的到达城市：");
            scanf("%s", flights[i].arrival_city);
            printf("请输入新的票价：");
            scanf("%f", &flights[i].price);

            printf("航班信息修改成功！\n");
            break;
        }
    }
    if (i == num_flights) {
        printf("未找到该航班！\n");
    }
}

void mune() {
    system("cls");
    printf("\n\n\n");
    printf("<<<<<<<<<<---------------------------------------------------->>>>>>>>>>\n");
    printf("                欢迎使用航空客运订票系统                 \n");
    printf("<<<<<<<<<<---------------------------------------------------->>>>>>>>>>\n");
    printf("\n\n<<<<<<<<<<<<----功能选择---->>>>>>>>>>>>>>>\n\n");
    printf("---------------1. 录入航班信息\n");
    printf("---------------2. 查询航班信息\n");
    printf("---------------3. 查询航班航线\n");
    printf("---------------4. 订票\n");
    printf("---------------5. 退票\n");
    printf("---------------6. 修改航班信息\n");
    printf("---------------7. 退出系统\n");
    printf("请选择操作：");
    
}


int main() {
    system("Color 1e");//系统背景颜色变化
    mune();
    int choice;
    scanf("%d", &choice);
    while (1) {
        
        switch (choice) {
        case 1:
            add_flight();
            break;
        case 2:
            search_flight();
            break;
        case 3:
            search_flight_list();
            break;
        case 4:
            book_ticket();
            break;
        case 5:
            cancel_ticket();
            break;
        case 6:
            modify_flight();
            break;
        case 7:
            printf("\n\t\t>>>>>>>>Welcome back！！<<<<<<<<<\n");
            return 0;
        default:
            printf("无效的操作！\n");
        }
        getch();
        mune();
        printf("请选择操作：");
        scanf("%d", &choice);
    }
    return 0;
}



