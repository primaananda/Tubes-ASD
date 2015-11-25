#include "head.h"

void addAkun (list_akun &A)
{
    first(A)=NULL;
}

address_akun alokasi_akun (infotype_akun x)
{

    address_akun A = new elmakun;
    A->info_akun= x;
    next(A) = NULL;
    prev(A) = NULL;
    return A;
}
void insertFirstAkun (list_akun &A, address_akun P)
{
    {
    if(first(A)==NULL)
    {

        first(A)=P;
        next(first(A))=NULL;
        next(P)=first(A);
    }
    else
    {
        next(P)=NULL;
        first(A)=P;
    }
    }
}

void insertLastAkun (list_akun &A, address_akun P)
{
    address_akun Q;
    Q=first(A);
    if(Q==NULL)
    {
        first(A)=P;
        next(first(A))=NULL;
    }
    else
    {
        while(next(Q)!=NULL)
        {
            Q=next(Q);
        }
        next(P)=NULL;
        next(Q)=P;
    }
}

void addStatus (list_status &S)
{
    first(S)=NULL;
    last(S)=NULL;
}

void deletefirst_akun(list_akun &A,address_akun &P)
{

    P=first(A);
    if(P==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else
    {
        first(A)=next(first(A));
        next(P)=NULL;
        cout<<"ID Akun yang dihapus "<<info_akun(P).id_akun<<endl;
    }
}

void deleteLast_status(list_status &S,address_status *P)
{
    P=last(S);
    last(S)=prev(last(S));
    prev(P)=NULL;
    next(last(S))=NULL;
    cout<<"ID Status yang dihapus "<<info_status(P).id_status<<endl;
}


//START BAGIAN PRIMA ANANDA
void insertNextAkun(list_akun &A, address_akun P, address_akun prec)
{
    if (first(A) == NULL){
        insertFirstAkun(A, P); ///tolong buatin dan samain prosedurnya
    }
    else {
        address_akun current = first(A);
        while(current != NULL) {
            if(current == prec) {
                if(next(current) == NULL) {
                    insertLastAkun(A, P); ///tolong buatin dan samain prosedurnya
                } else {
                    next(P) = next(current);
                    next(current) = P;
                    prev(next(P)) = P;
                    prev(P) = current;
                }
                break;
            }
            current = next(current);
        }
    }
}

void insertNextStatus(list_status &S, address_akun Q, address_status P, address_status prec) {
    ///pertama dicek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(Q)); ///buat dong fungsi atau prosedur find elemen ///masih eror
        /// ngecek list anak kosong apa nggak
        if(induk->lstatus) { ///masih eror
            insertFirstStatus(S, Q, P); ///masih eror voidnya belum ada
        } else {
            address_status current = first(induk->lstatus);
            while(current != NULL) {
                if(current == prec) {
                    /// menentukan apakah current merupakan elemen terakhir atau bukan
                    if(next(current) == NULL) {
                        insertLastStatus(S, Q, P); ///masih eror voidnya belum ada
                    } else {
                        next(P) = next(current);
                        next(current) = P;
                        prev(next(P)) = P;
                        prev(P) = current;
                    }
                    break;
                }
                current = next(current);
            }
        }
    }
}

void deleteFirstStatus(list_status &S, address_akun P, address_status Q){
    /// cek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(P)); ///buat dong fungsi atau prosedur find elemen ///masih eror;
        /// cek apakah list status kosong atau tidak
        if(first(induk->ltatus)) { ///masih eror
            /// cek apa ada satu elemen di status
            if(next(first(induk->lstatus)) == NULL) {
                first(induk->lstatus) = NULL;
                last(induk->lstatus) = NULL;
            } else {
                Q = first(induk->lstatus); ///masih eror
                first(induk->lstatus) = next(first(induk->lstatus));
                next(Q) = NULL; ///masih eror
                prev(first(induk->lstatus)) = NULL;
            }
        }
    }
}

void deleteLastStatus(list_status &S, address_akun P, address_status Q) {
    /// cek apakah list akun kosong atau tidak
    if(first(S) != NULL) {
        address_akun induk = find_element(S, info_akun(P)); ///buat dong fungsi atau prosedur find elemen ///masih eror;
        /// cek apakah list status kosong atau tidak
        if(first(induk->ltatus)) { ///masih eror
            /// cek apa ada satu elemen di status
            if(next(first(induk->lstatus)) == NULL) {
                deleteLastStatus(S, P, Q);
            } else {
                Q = last(induk->lstatus); ///masih eror
                last(induk->lstatus) = prev(Q);
                prev(Q) = NULL; ///masih eror
                next(last(induk->lstatus)) = NULL;
            }
        }
    }
}

void akundanStatus(list_status &S, list_akun &A){
    if(first(S) != NULL) {
        return 0;
        ///masih bingung
    }
}

void deleteLastAkun(list_akun &A, address_akun P) {
    if(first(A) != NULL) {
        address_akun current = first(A);
        if(next(current) == NULL) {
            deletefirst_akun(&A, P); ///MASIH ERROR
        } else {
            P = first(A);
            first(A) = prev(P);
            next(first(A)) = NULL;
            prev(P) = NULL;
        }
    }
}

///END PRIMA ANANDA
