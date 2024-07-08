// void SORT()
// {
//     set<string> SetDate;
//     ifstream in("income.txt");
//     vector<Transaction> t1;
//     int j=0;
//     while (in >> t1[j].userId >> t1[j].transactionId >> t1[j].transactionDate >> t1[j].title >> t1[j].description >> t1[j].accountId >> t1[j].entryDate >> t1[j].amount)
//     {
//         SetDate.insert(t1[j++].transactionDate);
//     }
//     in.close();
//     ofstream out("sorted_transaction.txt");

//     for(auto i =SetDate.begin() ; i != SetDate.end() ; i++)
//     {
//         for(int j=0;j<t1.size();j++)
//         {
//             if(t1[j].transactionDate == *i)
//             {
//                 out << t1[j].userId << " " << t1[j].transactionId << " " << t1[j].transactionDate << " " << t1[j].title << " " << t1[j].description << " " << t1[j].accountId << " " << t1[j].entryDate << " " << t1[j].amount << " " << endl;
//             }
//         }
//     }
//     out.close();
    
// }
