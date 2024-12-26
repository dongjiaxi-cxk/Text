#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// 账单记录结构体
typedef struct {
    char date[11];    // 日期格式：YYYY-MM-DD
    float amount;     // 金额
    char category[50]; // 类别
    char remark[100];  // 备注
} BillRecord;

// 全局变量：记录账单的数组，收入与支出分别存储
BillRecord income_records[MAX_RECORDS];
BillRecord expense_records[MAX_RECORDS];
int income_count = 0, expense_count = 0; // 记录数量

// 月度预算
float monthly_budget = 0;

// 函数声明
void record_income();
void record_expense();
void view_all_bills();
void query_bills();
void set_budget();
void view_monthly_statistics();
void print_menu();
int is_valid_date(const char* date);
int is_valid_amount(float amount);
void clear_input_buffer();

int main() {
    int choice;
    
    while(1) {
        print_menu();
        printf("请输入选项序号：");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1:
                record_income();
                break;
            case 2:
                record_expense();
                break;
            case 3:
                view_all_bills();
                break;
            case 4:
                query_bills();
                break;
            case 5:
                set_budget();
                break;
            case 6:
                view_monthly_statistics();
                break;
            case 7:
                printf("退出系统...\n");
                exit(0);
                break;
            default:
                printf("无效的选项，请重新输入！\n");
        }
    }
    return 0;
}

void print_menu() {
    printf("\n=================================\n");
    printf("欢迎使用个人账单管理系统\n");
    printf("=================================\n");
    printf("请选择操作：\n");
    printf("1. 记录收入\n");
    printf("2. 记录支出\n");
    printf("3. 查看所有账单\n");
    printf("4. 查询账单\n");
    printf("5. 设置月度预算\n");
    printf("6. 查看月度统计报告\n");
    printf("7. 退出系统\n");
}

void record_income() {
    if (income_count >= MAX_RECORDS) {
        printf("收入记录已满，无法添加新的收入！\n");
        return;
    }

    BillRecord new_record;
    printf("\n请输入收入信息：\n");

    // 输入日期
    while (1) {
        printf("日期（YYYY-MM-DD）：");
        fgets(new_record.date, 11, stdin);
        new_record.date[strcspn(new_record.date, "\n")] = '\0';  // 移除末尾的换行符
        if (is_valid_date(new_record.date)) {
            break;
        } else {
            printf("日期格式无效，请重新输入。\n");
        }
    }

    // 输入金额
    while (1) {
        printf("金额：");
        scanf("%f", &new_record.amount);
        clear_input_buffer();
        if (is_valid_amount(new_record.amount)) {
            break;
        } else {
            printf("金额无效，请重新输入（必须为正数）。\n");
        }
    }

    // 输入类别
    printf("类别（如工资、奖金等）：");
    fgets(new_record.category, 50, stdin);
    new_record.category[strcspn(new_record.category, "\n")] = '\0';  // 移除末尾的换行符

    // 输入备注
    printf("备注：");
    fgets(new_record.remark, 100, stdin);
    new_record.remark[strcspn(new_record.remark, "\n")] = '\0';  // 移除末尾的换行符

    income_records[income_count++] = new_record;
    printf("收入已成功记录！\n");
}

void record_expense() {
    if (expense_count >= MAX_RECORDS) {
        printf("支出记录已满，无法添加新的支出！\n");
        return;
    }

    BillRecord new_record;
    printf("\n请输入支出信息：\n");

    // 输入日期
    while (1) {
        printf("日期（YYYY-MM-DD）：");
        fgets(new_record.date, 11, stdin);
        new_record.date[strcspn(new_record.date, "\n")] = '\0';  // 移除末尾的换行符
        if (is_valid_date(new_record.date)) {
            break;
        } else {
            printf("日期格式无效，请重新输入。\n");
        }
    }

    // 输入金额
    while (1) {
        printf("金额：");
        scanf("%f", &new_record.amount);
        clear_input_buffer();
        if (is_valid_amount(new_record.amount)) {
            break;
        } else {
            printf("金额无效，请重新输入（必须为正数）。\n");
        }
    }

    // 输入类别
    printf("类别（如餐饮、交通、购物等）：");
    fgets(new_record.category, 50, stdin);
    new_record.category[strcspn(new_record.category, "\n")] = '\0';  // 移除末尾的换行符

    // 输入备注
    printf("备注：");
    fgets(new_record.remark, 100, stdin);
    new_record.remark[strcspn(new_record.remark, "\n")] = '\0';  // 移除末尾的换行符

    expense_records[expense_count++] = new_record;
    printf("支出已成功记录！\n");
}

void view_all_bills() {
    printf("\n--- 收入记录 ---\n");
    for (int i = 0; i < income_count; i++) {
        printf("日期：%s, 金额：%.2f, 类别：%s, 备注：%s\n", 
               income_records[i].date, 
               income_records[i].amount, 
               income_records[i].category, 
               income_records[i].remark);
    }

    printf("\n--- 支出记录 ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("日期：%s, 金额：%.2f, 类别：%s, 备注：%s\n", 
               expense_records[i].date, 
               expense_records[i].amount, 
               expense_records[i].category, 
               expense_records[i].remark);
    }
}

void query_bills() {
    // 这里只简单提供查询所有账单功能，可以扩展为按日期或类别查询。
    view_all_bills();
}

void set_budget() {
    printf("请输入您的月度预算金额：");
    scanf("%f", &monthly_budget);
    clear_input_buffer();
    printf("月度预算已设置为：%.2f\n", monthly_budget);
}

void view_monthly_statistics() {
    float total_income = 0, total_expense = 0;
    for (int i = 0; i < income_count; i++) {
        total_income += income_records[i].amount;
    }
    for (int i = 0; i < expense_count; i++) {
        total_expense += expense_records[i].amount;
    }

    printf("月度统计：\n");
    printf("总收入：%.2f\n", total_income);
    printf("总支出：%.2f\n", total_expense);
    printf("剩余预算：%.2f\n", monthly_budget - total_expense);
}

int is_valid_date(const char* date) {
    // 检查日期格式是否为YYYY-MM-DD
    if (strlen(date) != 10) return 0;
    if (date[4] != '-' || date[7] != '-') return 0;
    for (int i = 0; i < 10; i++) {
        if ((i != 4 && i != 7) && (date[i] < '0' || date[i] > '9')) return 0;
    }
    return 1;
}

int is_valid_amount(float amount) {
    return amount > 0;
}

void clear_input_buffer() {
    while (getchar() != '\n'); // 清除缓冲区的换行符
}

