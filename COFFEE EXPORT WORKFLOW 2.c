/*
 * ============================================================

 * Product: Kenyan Coffee Export Workflow
 *
 * Group Members:
 * 1. NYABARO CHRIS KINARO - 25/10415
 * 2. BERCYN ONYANGO - 23/05477
 * 3. MATHEW KARIUKI - 26/06603
 * 4.BETHWEL CHERUIYOT - 25/08011
 
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>

void displayTitle(FILE *fp);

int main()
{
    FILE *fp;

    int total_batches;
    int batch;

    fp = fopen("results.txt", "w");

    if (fp == NULL)
    {
        printf("Error creating results.txt file.\n");
        return 1;
    }

    displayTitle(fp);

    printf("\nEnter the number of coffee batches to process: ");
    scanf("%d", &total_batches);

    fprintf(fp, "\nTotal Batches to Process: %d\n\n", total_batches);

    for (batch = 1; batch <= total_batches; batch++)
    {
        char supplier[50];
        float weight_kg;

        int ripeness_ok;
        int moisture_ok;
        int no_foreign;

        int electricity_ok;

        int method;

        int grade;
        int defect_count;

        int bag_type;
        int num_bags;

        int phyto_ok;
        int coo_ok;
        int ico_ok;

        printf("\n====================================================\n");
        printf("PROCESSING BATCH %d\n", batch);
        printf("====================================================\n");

        fprintf(fp, "\n====================================================\n");
        fprintf(fp, "BATCH %d\n", batch);
        fprintf(fp, "====================================================\n");

        /* ==================== STAGE 1 ==================== */
        printf("\nRAW MATERIAL RECEPTION\n");

        printf("Enter supplier name: ");
        scanf("%s", supplier);

        printf("Enter weight received (kg): ");
        scanf("%f", &weight_kg);

        printf("Received %.2f kg from %s\n",
               weight_kg,
               supplier);

        fprintf(fp, "Supplier Name: %s\n", supplier);
        fprintf(fp, "Weight Received: %.2f kg\n", weight_kg);

     
        printf("\nBASIC INSPECTION\n");

        printf("Is ripeness level acceptable? (1=Yes, 0=No): ");
        scanf("%d", &ripeness_ok);

        printf("Is moisture level acceptable? (1=Yes, 0=No): ");
        scanf("%d", &moisture_ok);

        printf("No foreign matter detected? (1=Yes, 0=No): ");
        scanf("%d", &no_foreign);

        if (!(ripeness_ok && moisture_ok && no_foreign))
        {
            printf("\nBatch %d FAILED basic inspection.\n", batch);
            printf("Batch rejected.\n");

            fprintf(fp, "Inspection Result: FAILED\n");
            fprintf(fp, "Status: Batch Rejected\n");

            continue;
        }

        printf("Inspection PASSED.\n");

        fprintf(fp, "Inspection Result: PASSED\n");

       
        printf("\nELECTRICITY CHECK\n");

        printf("Is KPLC electricity available? (1=Yes, 0=No): ");
        scanf("%d", &electricity_ok);

        if (electricity_ok)
        {
            printf("KPLC power confirmed.\n");
            fprintf(fp, "Power Source: KPLC Electricity\n");
        }
        else
        {
            printf("Power unavailable. Switching to backup generator.\n");
            fprintf(fp, "Power Source: Backup Generator\n");
        }

        
        printf("\nPROCESSING / PREPARATION\n");

        printf("Select processing method:\n");
        printf("1. Wet Mill\n");
        printf("2. Dry Mill\n");
        printf("Enter choice: ");
        scanf("%d", &method);

        if (method == 1)
        {
            printf("\nWet milling selected.\n");
            printf("Pulping -> Fermentation -> Washing -> Drying\n");

            fprintf(fp, "Processing Method: Wet Mill\n");
        }
        else
        {
            printf("\nDry milling selected.\n");
            printf("Drying -> Hulling\n");

            fprintf(fp, "Processing Method: Dry Mill\n");
        }

        
        printf("\nQUALITY CHECK\n");

        printf("Enter coffee grade (1=AA, 2=AB, 3=C, 4=PB, 5=E): ");
        scanf("%d", &grade);

        printf("Enter defect count per 300g sample: ");
        scanf("%d", &defect_count);

        if (!(grade >= 1 && grade <= 4 && defect_count <= 11))
        {
            printf("\nBatch %d FAILED quality check.\n", batch);
            printf("Batch sent for reprocessing.\n");

            fprintf(fp, "Quality Check: FAILED\n");
            fprintf(fp, "Status: Sent for Reprocessing\n");

            continue;
        }

        printf("Quality Check PASSED.\n");

        fprintf(fp, "Quality Check: PASSED\n");

        if (grade == 1)
            fprintf(fp, "Grade Awarded: AA\n");
        else if (grade == 2)
            fprintf(fp, "Grade Awarded: AB\n");
        else if (grade == 3)
            fprintf(fp, "Grade Awarded: C\n");
        else
            fprintf(fp, "Grade Awarded: PB\n");

      
        printf("\nPACKAGING\n");

        printf("Select bag type:\n");
        printf("1. GrainPro Hermetic Liner\n");
        printf("2. Standard Jute Bag\n");
        printf("Enter choice: ");
        scanf("%d", &bag_type);

        printf("Enter number of 60kg bags: ");
        scanf("%d", &num_bags);

        printf("Packaging complete.\n");

        fprintf(fp, "Packaging Type: %s\n",
                bag_type == 1 ?
                "GrainPro Hermetic Liner" :
                "Standard Jute Bag");

        fprintf(fp, "Number of Bags: %d\n", num_bags);
        fprintf(fp, "Net Weight: %d kg\n", num_bags * 60);

        
        printf("\nEXPORT DECISION\n");

        printf("Phytosanitary certificate valid? (1=Yes, 0=No): ");
        scanf("%d", &phyto_ok);

        printf("Certificate of origin valid? (1=Yes, 0=No): ");
        scanf("%d", &coo_ok);

        printf("ICO certificate obtained? (1=Yes, 0=No): ");
        scanf("%d", &ico_ok);

        if (phyto_ok && coo_ok && ico_ok)
        {
            printf("\n*** EXPORT APPROVED ***\n");
            printf("Batch cleared for shipment.\n");

            fprintf(fp, "Export Status: APPROVED\n");
            fprintf(fp, "Shipment Cleared for Export\n");
        }
        else
        {
            printf("\nEXPORT ON HOLD\n");

            fprintf(fp, "Export Status: ON HOLD\n");

            if (!phyto_ok)
                fprintf(fp, "- Missing Phytosanitary Certificate\n");

            if (!coo_ok)
                fprintf(fp, "- Missing Certificate of Origin\n");

            if (!ico_ok)
                fprintf(fp, "- Missing ICO Certificate\n");
        }
    }

    printf("\n====================================================\n");
    printf("ALL BATCHES HAVE BEEN PROCESSED\n");
    printf("Results saved in results.txt\n");
    printf("====================================================\n");

    fprintf(fp, "\n====================================================\n");
    fprintf(fp, "ALL BATCHES PROCESSED\n");
    fprintf(fp, "END OF PROGRAM\n");
    fprintf(fp, "====================================================\n");

    fclose(fp);

    return 0;
}

void displayTitle(FILE *fp)
{
    printf("====================================================\n");
    printf("       COFFEE EXPORT WORKFLOW MANAGEMENT SYSTEM\n");
    printf("====================================================\n");

    printf("Group Members:\n");
    printf("1. NYABARO CHRIS KINARO - 25/10415\n");
    printf("2. BERCYN ONYANGO - 23/05477\n");
    printf("3. MATHEW KARIUKI - 25/06603\n");
    printf("4. BETHWEL CHERUIYOT - 25/08011\n");

    fprintf(fp, "====================================================\n");
    fprintf(fp, "COFFEE EXPORT WORKFLOW MANAGEMENT SYSTEM\n");
    fprintf(fp, "====================================================\n");

    fprintf(fp, "Group Members:\n");
    fprintf(fp, "1. NYABARO CHRIS KINARO - 25/10415\n");
    fprintf(fp, "2. BERCYN ONYANGO - 23/05477\n");
    fprintf(fp, "3. MATHEW KARIUKI - 25/06603\n");
    fprintf(fp, "4. BETHWEL CHERUIYOT - 25/08011\n");
}
