#include "../includes/ft_solve.h"

int		main(void)
{
	const char	*test[30];
	char		**answer;

// 단계 검증
	// 정상 단계
	test[0] = "/a.z";
	test[1] = "/a/a.z";
	test[2] = "/a/a/a.z";
	test[3] = "/a/a/a/a.z";
	test[4] = "/a/a/a/a/a.z";
	test[5] = "/.z";
	test[6] = "/a/a/a/a/a/a/a.z";
	test[7] = "/a/a/a/a/a/a/a/a.z";
	test[8] = "/a/a/a/a/a/a/a/a/a.z";
	test[9] = "/a/a/a/a/a/a/a/a/a/a.z";
	// 단계 예외
	test[10] = "a.z";
	test[11] = "/a/a/a/a/a/a/a/a/a/a/a/a/a.z";
// 파일명 버전 확장자
	// 파일명 O & 버전 O & 확장자 O
	test[12] = "/z_dlwn/c_v0.k";
	// 파일명 O & 버전 O & 확장자 X
	test[13] = "/z_dlwn/c_v0.0";
	// 파일명 O & 버전 X & 확장자 O
	test[14] = "/z_dlwn/c_v10.k";
	// 파일명 O & 버전 X & 확장자 X
	test[15] = "/z_dlwn/c_v10.1";
	// 파일명 X & 버전 O & 확장자 O
	test[16] = "/afda/z_dlwn/akae&_v9.c";
	// 파일명 X & 버전 O & 확장자 X
	test[17] = "/afda/z_dlwn/akae&_v9.1";
	// 파일명 X & 버전 X & 확장자 O
	test[18] = "/afda/z_dlwn/akae&_v10.c";
	// 파일명 X & 버전 X & 확장자 X
	test[19] = "/afda/z_dlwn/akae&_v10.1";
// 기타
	// 버전 인식
	test[20] = "/a3/a12/43a/c1093/dfdas/cisco.c";
	test[21] = "/a3/a12/43a/c1093/dfdas/cisco_v2.c";
	test[22] = "/a3/a12/43a/c1093/dfdas/cisco_v9.c";
	//	확장자 인식
	test[23] = "/a3/a12/43a/c1093/dfdas/cisco_v9.0";
	test[24] = "/a3/a12/43a/c1093/dfdas/cisco_v9.z";
	test[25] = "/a3/a12/43a/c1093/dfdas/cisco_v1.z";
	// 파일명 인식
	test[26] = "/a3/a12/43a/c1093/dfdas/sinjeong_v5.z";
	test[27] = "/a3/a12/43a/c1093/dfdas/sin.jeong_v5.z";
	test[28] = "/a3/a12/43a/c1093/dfdas/sin12jeong_v5.z";
	test[29] = "/a3/a12/43a/c1093/dfdas/sinjeong_v1.z";
	if ((answer = ft_solve(test, 30)))
		ft_print_answer(answer);
	ft_free_answer(answer);
}