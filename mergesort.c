#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/*merges two sorted array to form a new sorted array*/
void merge(int* array, int start, int mid, int end){
	/*take copies of two sorted arrays*/
	int size1 = mid - start + 1;
	int size2 = end - mid;
	int A[size1], B[size2];

	/*copy one part to array A*/
	for (int i = 0 ; i < size1; ++i)
		A[i] = array[start + i];

	/*copy another part to array B*/
	for (int i = 0 ; i < size2; ++i)
		B[i] = array[mid + 1 + i];

	/*indices to iterate through arrays*/
	int a_index = 0, b_index = 0, combinded_index = start;

	/*combine A and B to store in original array*/
	while (a_index  < size1 && b_index < size2){
		if (A[a_index] < B[b_index])
			array[combinded_index++] = A[a_index++];
		else
			array[combinded_index++] = B[b_index++];			
	}

	/*if A is exhausted then copy B entirely*/
	if (a_index == size1)
		while (b_index < size2)
			array[combinded_index++] = B[b_index++];

	/*if B is exhausted then copy A entirely*/
	if (b_index == size2)
		while (a_index < size1)
			array[combinded_index++] = A[a_index++];
}

/*sorts the given array of size N using merge sort algorithm*/
void mergeSort(int* array, int start, int end){
	/*check if array contains at least two elements to be sorted*/
	if (end > start){
		/*divide the array into two equal halves*/
		int mid = (start + end)/2;

		/*sort two halves recursively*/
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);

		/*merge two small sorted array to get a big sorted array*/
		merge(array, start, mid, end);
	}
}

/*populates the given array of size N with random integers*/
void populateArray(int* array, int N){
	/*seed the random number generator with time*/
	srand(time(NULL));

	/*iterate through all elements in array and populate them*/
	for (int i = 0 ; i < N; ++i)
		array[i] = rand() % 100;
}

/*prints the content of the array to console*/
void printArray(int* array, int N){
	for (int i = 0 ; i < N; ++i)
		printf ("%d ", array[i]);
	printf ("\n");
}

/*driver function: program execution begins from here*/
int main(){
	
	struct timeval start, end;
	/*used for computing the time difference*/
	unsigned long long int time1, time2, time_taken;	
	/*create an array of size 10*/
	int N = 1000;
	int array[1000]= { 5 ,18 ,26 ,30 ,32 ,43 ,76 ,80 ,90 ,94 ,97 ,107 ,111 ,112 ,128 ,129 ,130 ,139 ,140 ,141 ,143 ,168 ,174 ,184 ,198 ,208 ,210 ,213 ,223 ,228 ,231 ,240 ,241 ,258 ,272 ,288 ,309 ,311 ,324 ,331 ,336 ,337 ,364 ,400 ,409 ,425 ,432 ,441 ,450 ,454 ,455 ,465 ,470 ,471 ,476 ,492 ,495 ,501 ,504 ,509 ,538 ,550 ,576 ,578 ,582 ,593 ,623 ,634 ,637 ,651 ,655 ,667 ,676 ,683 ,694 ,708 ,715 ,716 ,739 ,743 ,744 ,750 ,753 ,778 ,780 ,782 ,785 ,789 ,794 ,814 ,828 ,836 ,855 ,863 ,868 ,890 ,915 ,920 ,952 ,971 ,975 ,977 ,993 ,996 ,1001 ,1003 ,1013 ,1031 ,1050 ,1054 ,1056 ,1071 ,1075 ,1081 ,1085 ,1102 ,1131 ,1134 ,1180 ,1196 ,1200 ,1205 ,1214 ,1218 ,1229 ,1236 ,1258 ,1259 ,1286 ,1289 ,1340 ,1381 ,1396 ,1418 ,1421 ,1423 ,1426 ,1429 ,1431 ,1433 ,1449 ,1464 ,1468 ,1493 ,1496 ,1515 ,1520 ,1529 ,1544 ,1549 ,1561 ,1562 ,1576 ,1579 ,1588 ,1590 ,1591 ,1600 ,1609 ,1630 ,1632 ,1638 ,1643 ,1645 ,1668 ,1695 ,1710 ,1726 ,1729 ,1730 ,1740 ,1744 ,1751 ,1756 ,1764 ,1768 ,1776 ,1786 ,1792 ,1802 ,1814 ,1820 ,1823 ,1837 ,1841 ,1896 ,1909 ,1913 ,1914 ,1919 ,1923 ,1941 ,1945 ,1974 ,1981 ,1985 ,1986 ,1998 ,2001 ,2038 ,2039 ,2055 ,2062 ,2063 ,2065 ,2082 ,2092 ,2096 ,2105 ,2124 ,2127 ,2129 ,2145 ,2146 ,2171 ,2177 ,2187 ,2189 ,2208 ,2216 ,2219 ,2220 ,2234 ,2235 ,2236 ,2245 ,2246 ,2248 ,2268 ,2273 ,2275 ,2286 ,2287 ,2291 ,2295 ,2300 ,2316 ,2330 ,2339 ,2354 ,2360 ,2367 ,2381 ,2385 ,2393 ,2399 ,2433 ,2442 ,2455 ,2471 ,2488 ,2496 ,2513 ,2531 ,2559 ,2562 ,2563 ,2572 ,2576 ,2582 ,2583 ,2586 ,2594 ,2598 ,2600 ,2620 ,2621 ,2624 ,2642 ,2646 ,2661 ,2664 ,2680 ,2702 ,2705 ,2721 ,2723 ,2743 ,2751 ,2764 ,2808 ,2811 ,2820 ,2821 ,2825 ,2829 ,2833 ,2836 ,2842 ,2850 ,2851 ,2860 ,2868 ,2875 ,2879 ,2883 ,2890 ,2891 ,2902 ,2903 ,2906 ,2911 ,2923 ,2951 ,2959 ,2976 ,2977 ,2979 ,2985 ,2987 ,2995 ,2998 ,3002 ,3010 ,3013 ,3015 ,3019 ,3030 ,3035 ,3045 ,3047 ,3055 ,3066 ,3080 ,3082 ,3085 ,3087 ,3089 ,3091 ,3092 ,3109 ,3125 ,3129 ,3182 ,3200 ,3216 ,3223 ,3242 ,3246 ,3257 ,3263 ,3265 ,3266 ,3270 ,3293 ,3296 ,3300 ,3353 ,3355 ,3362 ,3368 ,3371 ,3372 ,3385 ,3403 ,3409 ,3410 ,3424 ,3440 ,3443 ,3448 ,3486 ,3487 ,3493 ,3496 ,3512 ,3513 ,3522 ,3527 ,3532 ,3547 ,3559 ,3560 ,3563 ,3564 ,3570 ,3571 ,3572 ,3607 ,3623 ,3625 ,3631 ,3635 ,3639 ,3643 ,3645 ,3650 ,3653 ,3669 ,3678 ,3689 ,3739 ,3760 ,3767 ,3774 ,3783 ,3786 ,3797 ,3828 ,3835 ,3847 ,3862 ,3869 ,3880 ,3883 ,3889 ,3905 ,3909 ,3911 ,3918 ,3920 ,3921 ,3923 ,3924 ,3928 ,3950 ,3953 ,3959 ,3962 ,3975 ,3977 ,3998 ,3999 ,4015 ,4041 ,4065 ,4077 ,4120 ,4123 ,4127 ,4134 ,4138 ,4168 ,4200 ,4227 ,4237 ,4246 ,4257 ,4258 ,4287 ,4303 ,4336 ,4338 ,4344 ,4354 ,4357 ,4358 ,4366 ,4369 ,4371 ,4382 ,4394 ,4398 ,4403 ,4405 ,4420 ,4434 ,4442 ,4446 ,4484 ,4505 ,4514 ,4517 ,4519 ,4524 ,4528 ,4533 ,4538 ,4543 ,4545 ,4550 ,4560 ,4565 ,4566 ,4580 ,4583 ,4589 ,4593 ,4594 ,4606 ,4612 ,4620 ,4626 ,4639 ,4648 ,4658 ,4666 ,4673 ,4676 ,4685 ,4696 ,4730 ,4735 ,4744 ,4763 ,4783 ,4784 ,4789 ,4790 ,4820 ,4825 ,4831 ,4849 ,4857 ,4866 ,4889 ,4907 ,4924 ,4927 ,4930 ,4931 ,4935 ,4938 ,4964 ,4992 ,4995 ,5009 ,5021 ,5027 ,5028 ,5029 ,5055 ,5064 ,5072 ,5078 ,5082 ,5084 ,5087 ,5099 ,5104 ,5123 ,5134 ,5138 ,5174 ,5181 ,5183 ,5250 ,5262 ,5274 ,5288 ,5297 ,5312 ,5313 ,5325 ,5328 ,5332 ,5338 ,5345 ,5354 ,5355 ,5367 ,5380 ,5392 ,5397 ,5420 ,5423 ,5424 ,5426 ,5475 ,5485 ,5492 ,5499 ,5501 ,5502 ,5510 ,5516 ,5530 ,5546 ,5561 ,5563 ,5578 ,5585 ,5591 ,5600 ,5613 ,5617 ,5618 ,5621 ,5625 ,5632 ,5638 ,5647 ,5670 ,5684 ,5695 ,5707 ,5715 ,5732 ,5776 ,5784 ,5794 ,5795 ,5797 ,5803 ,5808 ,5816 ,5843 ,5850 ,5861 ,5862 ,5889 ,5900 ,5901 ,5921 ,5936 ,5962 ,5987 ,6012 ,6018 ,6020 ,6031 ,6061 ,6068 ,6073 ,6098 ,6101 ,6116 ,6124 ,6126 ,6138 ,6141 ,6151 ,6159 ,6177 ,6183 ,6192 ,6194 ,6209 ,6212 ,6213 ,6261 ,6266 ,6288 ,6329 ,6330 ,6350 ,6363 ,6373 ,6404 ,6426 ,6432 ,6437 ,6447 ,6449 ,6451 ,6464 ,6476 ,6508 ,6516 ,6518 ,6527 ,6536 ,6547 ,6571 ,6609 ,6625 ,6626 ,6630 ,6638 ,6640 ,6645 ,6656 ,6669 ,6677 ,6679 ,6680 ,6693 ,6724 ,6747 ,6750 ,6766 ,6783 ,6784 ,6799 ,6800 ,6813 ,6823 ,6827 ,6836 ,6854 ,6859 ,6861 ,6879 ,6889 ,6898 ,6907 ,6911 ,6916 ,6924 ,6940 ,6952 ,6954 ,6962 ,6978 ,6980 ,6992 ,6996 ,7003 ,7008 ,7019 ,7026 ,7029 ,7030 ,7031 ,7051 ,7064 ,7065 ,7067 ,7069 ,7108 ,7118 ,7121 ,7126 ,7130 ,7131 ,7147 ,7158 ,7165 ,7176 ,7204 ,7222 ,7234 ,7237 ,7257 ,7264 ,7280 ,7293 ,7296 ,7303 ,7305 ,7310 ,7322 ,7349 ,7382 ,7384 ,7396 ,7403 ,7425 ,7432 ,7433 ,7468 ,7472 ,7491 ,7500 ,7516 ,7522 ,7536 ,7539 ,7546 ,7560 ,7561 ,7563 ,7566 ,7577 ,7591 ,7604 ,7612 ,7616 ,7633 ,7639 ,7650 ,7662 ,7672 ,7678 ,7682 ,7689 ,7695 ,7735 ,7736 ,7740 ,7742 ,7771 ,7773 ,7774 ,7778 ,7779 ,7806 ,7807 ,7809 ,7814 ,7815 ,7816 ,7817 ,7818 ,7831 ,7856 ,7857 ,7860 ,7862 ,7864 ,7872 ,7873 ,7874 ,7880 ,7896 ,7906 ,7907 ,7912 ,7919 ,7921 ,7931 ,7935 ,7941 ,7947 ,7948 ,7952 ,7978 ,7993 ,7998 ,8013 ,8029 ,8038 ,8040 ,8052 ,8102 ,8111 ,8112 ,8114 ,8116 ,8117 ,8127 ,8131 ,8157 ,8161 ,8163 ,8165 ,8166 ,8187 ,8197 ,8208 ,8227 ,8230 ,8238 ,8272 ,8280 ,8300 ,8305 ,8315 ,8325 ,8343 ,8347 ,8350 ,8364 ,8379 ,8393 ,8394 ,8404 ,8448 ,8457 ,8477 ,8480 ,8502 ,8555 ,8565 ,8587 ,8588 ,8589 ,8604 ,8613 ,8621 ,8628 ,8631 ,8635 ,8643 ,8649 ,8663 ,8671 ,8679 ,8699 ,8709 ,8711 ,8713 ,8735 ,8763 ,8766 ,8773 ,8776 ,8783 ,8787 ,8789 ,8793 ,8795 ,8819 ,8830 ,8869 ,8893 ,8896 ,8897 ,8910 ,8930 ,8936 ,8943 ,8998 ,9000 ,9005 ,9034 ,9041 ,9049 ,9061 ,9072 ,9076 ,9099 ,9113 ,9128 ,9141 ,9144 ,9145 ,9147 ,9158 ,9168 ,9175 ,9177 ,9178 ,9180 ,9182 ,9185 ,9186 ,9187 ,9195 ,9206 ,9223 ,9233 ,9246 ,9247 ,9252 ,9254 ,9275 ,9278 ,9281 ,9290 ,9291 ,9300 ,9305 ,9309 ,9323 ,9328 ,9347 ,9357 ,9361 ,9372 ,9373 ,9379 ,9398 ,9399 ,9406 ,9410 ,9457 ,9464 ,9471 ,9492 ,9503 ,9512 ,9535 ,9558 ,9565 ,9575 ,9577 ,9580 ,9587 ,9592 ,9616 ,9625 ,9626 ,9632 ,9651 ,9659 ,9667 ,9670 ,9672 ,9678 ,9680 ,9689 ,9705 ,9712 ,9729 ,9742 ,9760 ,9792 ,9796 ,9806 ,9808 ,9814 ,9819 ,9822 ,9834 ,9845 ,9852 ,9868 ,9871 ,9873 ,9877 ,9907 ,9930 ,9943 ,9946 ,9951 ,9968 ,9969 ,9976 ,9992};
	
	//populateArray(array, N);

	/*print the original content of the array*/
	printf ("Original array: ");
	printArray(array, N);
	
	gettimeofday(&start, NULL);	

	/*sort the array using merge sort algorithm*/
	mergeSort(array, 0, N-1);
	
	gettimeofday(&end, NULL);

	/*compute the time taken in microseconds*/
	time1 = (start.tv_sec * 1000000 + start.tv_usec);
	time2 = (end.tv_sec * 1000000 + end.tv_usec);

	/*compute the difference in time*/
	time_taken = time2 - time1;	
	

	/*print the sorted content of the array*/
	printf ("Sorted array: ");
	printArray(array, N);

	printf ("Time taken: %lluus\n", time_taken);

	/*return 0 to caller to indicate normal termination of program*/
	return 0;
}