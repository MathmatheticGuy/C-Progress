// void writeToFile(char path[100]){
//     FILE *fp;
//     fp = fopen(path, "w");
    
//     if (fp == NULL){
//         printf("Error opening file.\n");
//         return;
//     }

//     Student *current = head;
//     while (current != NULL){
//         fprintf("%s %s %.2f\n", current->studentID, current->studentName, current->avgMark);
//         current = current->next;
//     }

//     fclose(fp);    
// }