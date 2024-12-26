#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// �˵���¼�ṹ��
typedef struct {
    char date[11];    // ���ڸ�ʽ��YYYY-MM-DD
    float amount;     // ���
    char category[50]; // ���
    char remark[100];  // ��ע
} BillRecord;

// ȫ�ֱ�������¼�˵������飬������֧���ֱ�洢
BillRecord income_records[MAX_RECORDS];
BillRecord expense_records[MAX_RECORDS];
int income_count = 0, expense_count = 0; // ��¼����

// �¶�Ԥ��
float monthly_budget = 0;

// ��������
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
        printf("������ѡ����ţ�");
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
                printf("�˳�ϵͳ...\n");
                exit(0);
                break;
            default:
                printf("��Ч��ѡ����������룡\n");
        }
    }
    return 0;
}

void print_menu() {
    printf("\n=================================\n");
    printf("��ӭʹ�ø����˵�����ϵͳ\n");
    printf("=================================\n");
    printf("��ѡ�������\n");
    printf("1. ��¼����\n");
    printf("2. ��¼֧��\n");
    printf("3. �鿴�����˵�\n");
    printf("4. ��ѯ�˵�\n");
    printf("5. �����¶�Ԥ��\n");
    printf("6. �鿴�¶�ͳ�Ʊ���\n");
    printf("7. �˳�ϵͳ\n");
}

void record_income() {
    if (income_count >= MAX_RECORDS) {
        printf("�����¼�������޷�����µ����룡\n");
        return;
    }

    BillRecord new_record;
    printf("\n������������Ϣ��\n");

    // ��������
    while (1) {
        printf("���ڣ�YYYY-MM-DD����");
        fgets(new_record.date, 11, stdin);
        new_record.date[strcspn(new_record.date, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�
        if (is_valid_date(new_record.date)) {
            break;
        } else {
            printf("���ڸ�ʽ��Ч�����������롣\n");
        }
    }

    // ������
    while (1) {
        printf("��");
        scanf("%f", &new_record.amount);
        clear_input_buffer();
        if (is_valid_amount(new_record.amount)) {
            break;
        } else {
            printf("�����Ч�����������루����Ϊ��������\n");
        }
    }

    // �������
    printf("����繤�ʡ�����ȣ���");
    fgets(new_record.category, 50, stdin);
    new_record.category[strcspn(new_record.category, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�

    // ���뱸ע
    printf("��ע��");
    fgets(new_record.remark, 100, stdin);
    new_record.remark[strcspn(new_record.remark, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�

    income_records[income_count++] = new_record;
    printf("�����ѳɹ���¼��\n");
}

void record_expense() {
    if (expense_count >= MAX_RECORDS) {
        printf("֧����¼�������޷�����µ�֧����\n");
        return;
    }

    BillRecord new_record;
    printf("\n������֧����Ϣ��\n");

    // ��������
    while (1) {
        printf("���ڣ�YYYY-MM-DD����");
        fgets(new_record.date, 11, stdin);
        new_record.date[strcspn(new_record.date, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�
        if (is_valid_date(new_record.date)) {
            break;
        } else {
            printf("���ڸ�ʽ��Ч�����������롣\n");
        }
    }

    // ������
    while (1) {
        printf("��");
        scanf("%f", &new_record.amount);
        clear_input_buffer();
        if (is_valid_amount(new_record.amount)) {
            break;
        } else {
            printf("�����Ч�����������루����Ϊ��������\n");
        }
    }

    // �������
    printf("������������ͨ������ȣ���");
    fgets(new_record.category, 50, stdin);
    new_record.category[strcspn(new_record.category, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�

    // ���뱸ע
    printf("��ע��");
    fgets(new_record.remark, 100, stdin);
    new_record.remark[strcspn(new_record.remark, "\n")] = '\0';  // �Ƴ�ĩβ�Ļ��з�

    expense_records[expense_count++] = new_record;
    printf("֧���ѳɹ���¼��\n");
}

void view_all_bills() {
    printf("\n--- �����¼ ---\n");
    for (int i = 0; i < income_count; i++) {
        printf("���ڣ�%s, ��%.2f, ���%s, ��ע��%s\n", 
               income_records[i].date, 
               income_records[i].amount, 
               income_records[i].category, 
               income_records[i].remark);
    }

    printf("\n--- ֧����¼ ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("���ڣ�%s, ��%.2f, ���%s, ��ע��%s\n", 
               expense_records[i].date, 
               expense_records[i].amount, 
               expense_records[i].category, 
               expense_records[i].remark);
    }
}

void query_bills() {
    // ����ֻ���ṩ��ѯ�����˵����ܣ�������չΪ�����ڻ�����ѯ��
    view_all_bills();
}

void set_budget() {
    printf("�����������¶�Ԥ���");
    scanf("%f", &monthly_budget);
    clear_input_buffer();
    printf("�¶�Ԥ��������Ϊ��%.2f\n", monthly_budget);
}

void view_monthly_statistics() {
    float total_income = 0, total_expense = 0;
    for (int i = 0; i < income_count; i++) {
        total_income += income_records[i].amount;
    }
    for (int i = 0; i < expense_count; i++) {
        total_expense += expense_records[i].amount;
    }

    printf("�¶�ͳ�ƣ�\n");
    printf("�����룺%.2f\n", total_income);
    printf("��֧����%.2f\n", total_expense);
    printf("ʣ��Ԥ�㣺%.2f\n", monthly_budget - total_expense);
}

int is_valid_date(const char* date) {
    // ������ڸ�ʽ�Ƿ�ΪYYYY-MM-DD
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
    while (getchar() != '\n'); // ����������Ļ��з�
}

