#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct dataPembeli
{
    int tanggalTransaksi;
    int bulanTransaksi;
    int tahunTransaksi;
    char namaPelanggan[100];
    char jenisProduk[100];
    char namaProduk[100];
    int jumlahProduk;
    long long int hargaProduk;
    long long int totalpembayaran;
} var;

unsigned int masukkanpilihan();
void pembelianProduk ();
void cekPembelianTanggal ();
void cekPembelianProdukTerbanyak ();

//main function
int main(void)
{
	printf ("--------------------------------------------------------");
	printf ("\n Selamat Datang di Aplikasi Choco Baby & Children Store!\n");
    printf ("--------------------------------------------------------\n");
	FILE *cfAplikasi;
    cfAplikasi = fopen("sales.txt","a+");
    if(cfAplikasi == NULL)
    {
        printf ("Error to Open File!\n");
    }
    else
    {
        unsigned int pilihan;
        while ((pilihan = masukkanpilihan()) != 4)
        {
            switch(pilihan)
            {
                case 1:
                pembelianProduk();
                break;
                case 2:
                cekPembelianTanggal();
                break;
                case 3:
                cekPembelianProdukTerbanyak();
                break;
                default:
                printf ("\n Pilihan Anda Salah atau Tidak Valid!\n");
                break;
            }
        }
        printf("\n ---------------------------------------------------------------------\n");
		printf(" Terimakasih sudah menggunakan Program Choco Baby & Children Store!\n");
        printf(" ---------------------------------------------------------------------\n");
    }
    fclose (cfAplikasi);
    return 0;
}

void sorting (int a, int b, struct dataPembeli A[])
{
    var.tanggalTransaksi = A[a].tanggalTransaksi;
    var.bulanTransaksi = A[a].bulanTransaksi;
    var.tahunTransaksi = A[a].tahunTransaksi;
    strcpy(var.namaPelanggan,A[a].namaPelanggan);
    strcpy(var.jenisProduk,A[a].jenisProduk);
    strcpy(var.namaProduk,A[a].namaProduk);
    var.jumlahProduk = A[a].jumlahProduk;
    var.hargaProduk = A[a].hargaProduk;
    var.totalpembayaran = A[a].totalpembayaran;
    A[a].tanggalTransaksi = A[b].tanggalTransaksi;
    A[a].bulanTransaksi = A[b].bulanTransaksi;
    A[a].tahunTransaksi = A[b].tahunTransaksi;
    strcpy(A[a].namaPelanggan,A[b].namaPelanggan);
    strcpy(A[a].jenisProduk,A[b].jenisProduk);
    strcpy(A[a].namaProduk,A[b].namaProduk);
    A[a].jumlahProduk = A[b].jumlahProduk;
    A[a].hargaProduk = A[b].hargaProduk;
    A[a].totalpembayaran = A[b].totalpembayaran;
    A[b].tanggalTransaksi = var.tanggalTransaksi;
    A[b].bulanTransaksi = var.bulanTransaksi;
    A[b].tahunTransaksi = var.tahunTransaksi;
    strcpy(A[b].namaPelanggan,var.namaPelanggan);
    strcpy(A[b].jenisProduk,var.jenisProduk);
    strcpy(A[b].namaProduk,var.namaProduk);
    A[b].jumlahProduk = var.jumlahProduk;
    A[b].hargaProduk = var.hargaProduk;
    A[b].totalpembayaran = var.totalpembayaran;
}

void urut1 (struct dataPembeli com1[], int x)
{
	int i, j;
    for ( i = 0; i < x-1; i++)
    {
        for( j = 1; j < x-i; j++)
        {
            if(com1[j-1].tahunTransaksi > com1[j].tahunTransaksi)
            {
                sorting (j-1, j, com1);
            }
            else if(com1[j-1].tahunTransaksi == com1[j].tahunTransaksi)
            {
                if (com1[j-1].bulanTransaksi > com1[j].bulanTransaksi)
                {
                    sorting (j-1, j, com1);
                } else if (com1[j-1].bulanTransaksi == com1[j].bulanTransaksi) {
                	if (com1[j-1].tanggalTransaksi > com1[j].tanggalTransaksi) {
                		sorting (j-1, j, com1);
					}
				}
            }
          }
    }
}

void urut2 (struct dataPembeli com2[], int x)
{
	int i,j;
    for (i = 0; i < x-1; i++)
    {
        for (j = 1; j < x-i; j++)
        {
            if(com2[j-1].jumlahProduk < com2[j].jumlahProduk)
            {
                sorting (j-1, j, com2);
            }
        }
    }
}

//pembelianProduk function
void pembelianProduk ()
{
    FILE *pembelianProduk;
    pembelianProduk = fopen ("sales.txt","a+");
    if (pembelianProduk == NULL)
    {
        printf ("Cannot Processing!\n");
        exit(1);
    }
    struct dataPembeli pembeli;
    printf ("\n Masukkan Tanggal Transaksi (tanggal bulan tahun): "); scanf ("%d %d %d",&pembeli.tanggalTransaksi,&pembeli.bulanTransaksi,&pembeli.tahunTransaksi);
    printf (" Masukkan Nama Anda : ");
	scanf ("%s",pembeli.namaPelanggan);
	int jenis, namaproduk;
    printf (" Masukkan Jenis Produk yang ingin dipesan : \n");
    printf (" 1 Popok Bayi\n 2 Susu\n 3 Bubur Bayi\n 4 Botol Susu Bayi\n 5 Mainan Anak - Anak\n");
    printf (" Jenis produk yang ingin dipesan : ");
	scanf ("%d",&jenis);
	if (jenis == 1)
    {
        printf (" Masukkan Nama Produk yang ingin dipesan : \n");
        printf (" 1 MamyPoko\n 2 Sweety\n");
        scanf("%d",&namaproduk);
        strcpy(pembeli.jenisProduk,"Popok_Bayi");
        if (namaproduk==1)
        {
            strcpy(pembeli.namaProduk,"Mamy_Poko");
            pembeli.hargaProduk = 30000;
        }
        else if (namaproduk==2)
        {
            strcpy(pembeli.namaProduk,"Sweety");
            pembeli.hargaProduk = 40000;
        }
    }
    else if (jenis == 2)
    {
        printf (" Masukkan Nama Produk yang ingin dipesan : \n");
        printf (" 1 Bebelac\n 2 SGM\n");
        scanf("%d",&namaproduk);
        strcpy(pembeli.jenisProduk,"Susu_Bayi");
        if (namaproduk==1)
        {
            strcpy(pembeli.namaProduk,"Bebelac");
            pembeli.hargaProduk = 20000;
        }
        else if (namaproduk==2)
        {
            strcpy(pembeli.namaProduk,"SGM");
            pembeli.hargaProduk = 25000;
        }
    }
    else if (jenis == 3)
    {
        printf (" Masukkan Nama Produk yang ingin dipesan : \n");
        printf (" 1 Promina\n 2 Milna\n");
        scanf("%d",&namaproduk);
        strcpy(pembeli.jenisProduk,"Bubur_Bayi");
        if (namaproduk==1)
        {
            strcpy(pembeli.namaProduk,"Promina");
            pembeli.hargaProduk = 15000;
        }
        else if (namaproduk==2)
        {
            strcpy(pembeli.namaProduk,"Milna");
            pembeli.hargaProduk = 20000;
        }
    }
    else if (jenis == 4)
    {
       printf (" Masukkan Nama Produk yang ingin dipesan : \n");
        printf (" 1 Pigeon\n 2 Huki\n");
        scanf("%d",&namaproduk);
        strcpy(pembeli.jenisProduk,"BtlSusuBayi");
        if (namaproduk==1)
        {
            strcpy(pembeli.namaProduk,"Pigeon");
            pembeli.hargaProduk = 10000;
        }
        else if (namaproduk==2)
        {
            strcpy(pembeli.namaProduk,"Huki");
            pembeli.hargaProduk = 15000;
        }
    }
    else if (jenis == 5)
    {
        printf (" Masukkan Nama Produk yang ingin dipesan : \n");
        printf (" 1 Bola\n 2 Tenda\n 3 Boneka\n 4 PlayDoh\n 5 Lego\n");
        scanf("%d",&namaproduk);
        strcpy(pembeli.jenisProduk,"Mainan_Anak");
        if (namaproduk==1)
        {
            strcpy(pembeli.namaProduk,"Bola");
            pembeli.hargaProduk = 5000;
        }
        else if (namaproduk==2)
        {
            strcpy(pembeli.namaProduk,"Tenda");
            pembeli.hargaProduk = 50000;
        }
        else if (namaproduk==3)
        {
            strcpy(pembeli.namaProduk,"Boneka");
            pembeli.hargaProduk = 20000;
        }
         else if (namaproduk==4)
        {
            strcpy(pembeli.namaProduk,"PlayDoh");
            pembeli.hargaProduk = 25000;
        }
         else if (namaproduk==5)
        {
            strcpy(pembeli.namaProduk,"Lego");
            pembeli.hargaProduk = 20000;
        }
    }
    printf (" Masukkan Jumlah Produk yang Diinginkan : ");
    scanf ("%d",&pembeli.jumlahProduk);
    pembeli.totalpembayaran = pembeli.jumlahProduk*pembeli.hargaProduk;
    printf("\n------------------------------------");
	printf ("\n Terima kasih atas Transaksinya!\n");
	printf("------------------------------------\n");
	
    //fprintf (pembelianProduk," Tanggal Transaksi\tNama Pelanggan\tJenis Produk\tNama Produk\tJumlah Produk\tHarga Produk\tTotal Pembayaran\n");
    fprintf (pembelianProduk,"%d %d %d %s %s %s %d %lld %lld\n",pembeli.tanggalTransaksi,pembeli.bulanTransaksi,pembeli.tahunTransaksi,pembeli.namaPelanggan,pembeli.jenisProduk,pembeli.namaProduk,pembeli.jumlahProduk,pembeli.hargaProduk,pembeli.totalpembayaran);
    fclose (pembelianProduk);
}

void cekPembelianTanggal()
{
    struct dataPembeli sorting1[1000]; 
    int go = 0, i;
    FILE *Produk;
    Produk = fopen("sales.txt","r");
    if (Produk == NULL)
    {
        printf ("\n Data tidak Ditemukan.\n");
    }
   while(!(feof(Produk)))
    {
        fscanf (Produk,"%d %d %d %s %s %s %d %lld %lld\n",&sorting1[go].tanggalTransaksi,&sorting1[go].bulanTransaksi,&sorting1[go].tahunTransaksi,sorting1[go].namaPelanggan,sorting1[go].jenisProduk,sorting1[go].namaProduk,&sorting1[go].jumlahProduk,&sorting1[go].hargaProduk,&sorting1[go].totalpembayaran);
        go++;
        
        
    }
    urut1(sorting1, go);
    printf("\nCetak Laporan berdasarkan Tanggal Transaksi");
    printf("\n=======================================================================");
    printf("\nTanggal\t\tNama\tJenis\t\tProduk\tJumlah\tHarga\tTotal");
    printf("\n-----------------------------------------------------------------------\n");
    for(i=0; i<go; i++){
    	printf("%d/%d/%d\t%s\t%s\t%s\t   %d\t%lld\t%lld\n",sorting1[i].tanggalTransaksi,sorting1[i].bulanTransaksi,sorting1[i].tahunTransaksi,sorting1[i].namaPelanggan,sorting1[i].jenisProduk,sorting1[i].namaProduk,sorting1[i].jumlahProduk,sorting1[i].hargaProduk,sorting1[i].totalpembayaran);
	}
	printf("-----------------------------------------------------------------------\n");
	printf("*transaksi terbaru paling bawah\n");
    fclose(Produk);
}

void cekPembelianProdukTerbanyak ()
{
	int i;
    struct dataPembeli sorting2[1000];
    int go = 0;
    FILE *cekProdukTerbanyak;
    cekProdukTerbanyak = fopen ("sales.txt","r");
    if (cekProdukTerbanyak == NULL)
    {
        printf ("\n Data tidak Ditemukan.\n");
    }
    while (!(feof(cekProdukTerbanyak)))
    {
        fscanf (cekProdukTerbanyak, "%d %d %d %s %s %s %d %lld %lld\n",&sorting2[go].tanggalTransaksi,&sorting2[go].bulanTransaksi,&sorting2[go].tahunTransaksi,sorting2[go].namaPelanggan,sorting2[go].jenisProduk,sorting2[go].namaProduk,&sorting2[go].jumlahProduk,&sorting2[go].hargaProduk,&sorting2[go].totalpembayaran);
        go++;
    }
    urut2(sorting2, go);
    printf("\nCetak Laporan berdasarkan Banyak Produk yang Terjual");
    printf("\n=======================================================================");
    printf("\nTanggal\t\tNama\tJenis\t\tProduk\tJumlah\tHarga\tTotal\n");
    printf("-----------------------------------------------------------------------\n");
    for(i=0; i<go; i++){
    	printf("%d/%d/%d\t%s\t%s\t%s\t   %d\t%lld\t%lld\n",sorting2[i].tanggalTransaksi,sorting2[i].bulanTransaksi,sorting2[i].tahunTransaksi,sorting2[i].namaPelanggan,sorting2[i].jenisProduk,sorting2[i].namaProduk,sorting2[i].jumlahProduk,sorting2[i].hargaProduk,sorting2[i].totalpembayaran);
	}
	printf("-----------------------------------------------------------------------\n");
    fclose(cekProdukTerbanyak);
}

unsigned int masukkanpilihan()
{

    printf ("\n Silahkan pilih nomor sesuai dengan kegiatan transaksi :\n");
    printf (" \n\n 1. Pembelian produk.\n");
    printf (" \n 2. Cek Data Pembelian Sesuai Tanggal Transaksi.\n");
    printf (" \n 3. Cek Data Pembelian Sesuai Banyak Produk yang Terjual.\n");
    printf (" \n 4. Akhiri transaksi.\n\n");
    printf (" \n Masukkan Nomor yang ingin anda input (1 / 2 / 3 / 4) : ");
    unsigned int menupilihan;
    scanf ("%u",&menupilihan);
    return menupilihan;
}
