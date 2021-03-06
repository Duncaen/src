# $OpenBSD: Makefile,v 1.11 2017/04/28 11:28:20 kettenis Exp $

.include <bsd.own.mk>

LLVM_V=			4.0.0
CLANG_INTR_INCDIR=	/usr/lib/clang/${LLVM_V}/include

TBLGEN= ${.OBJDIR}/../../../clang-tblgen/clang-tblgen
CLANG_INC=${.CURDIR}/../../../../../llvm/tools/clang/include

.PATH:	${.CURDIR}/../../../../../llvm/tools/clang/lib/Headers

GEN=
HEADERS=	stdalign.h \
		stdatomic.h \
		stdnoreturn.h \
		tgmath.h \
		unwind.h \
		varargs.h \
		module.modulemap \

.if ${MACHINE_ARCH} == "aarch64" || ${MACHINE_ARCH} == "arm"
GEN+=		arm_neon.h
HEADERS+=	arm_acle.h ${GEN}
.elif ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "i386"
HEADERS+=	adxintrin.h \
		ammintrin.h \
		avx2intrin.h \
		avx512bwintrin.h \
		avx512cdintrin.h \
		avx512dqintrin.h \
		avx512erintrin.h \
		avx512fintrin.h \
		avx512ifmaintrin.h \
		avx512ifmavlintrin.h \
		avx512pfintrin.h \
		avx512vbmiintrin.h \
		avx512vbmivlintrin.h \
		avx512vlbwintrin.h \
		avx512vlcdintrin.h \
		avx512vldqintrin.h \
		avx512vlintrin.h \
		avxintrin.h \
		bmi2intrin.h \
		bmiintrin.h \
		cpuid.h \
		clflushoptintrin.h \
		emmintrin.h \
		f16cintrin.h \
		fma4intrin.h \
		fmaintrin.h \
		fxsrintrin.h \
		ia32intrin.h \
		immintrin.h \
		lzcntintrin.h \
		mm3dnow.h \
		mmintrin.h \
		mm_malloc.h \
		mwaitxintrin.h \
		nmmintrin.h \
		pkuintrin.h \
		pmmintrin.h \
		popcntintrin.h \
		prfchwintrin.h \
		rdseedintrin.h \
		rtmintrin.h \
		shaintrin.h \
		smmintrin.h \
		tbmintrin.h \
		tmmintrin.h \
		wmmintrin.h \
		__wmmintrin_aes.h \
		__wmmintrin_pclmul.h \
		x86intrin.h \
		xmmintrin.h \
		xopintrin.h \
		xsaveintrin.h \
		xsaveoptintrin.h \
		xsavecintrin.h \
		xsavesintrin.h \
		xtestintrin.h
.elif ${MACHINE_ARCH} == "powerpc"
HEADERS+=	altivec.h \
		htmintrin.h \
		htmxlintrin.h
.endif

all:	${HEADERS}

depend:
	# Nothing here so far ...

clean cleandir:
	rm -f ${GEN}

install includes: ${HEADERS}
.for dir in /usr/lib/clang /usr/lib/clang/${LLVM_V} ${CLANG_INTR_INCDIR}
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${DIRMODE} \
	    ${DESTDIR}${dir}
.endfor
	${INSTALL} ${INSTALL_COPY} -o ${BINOWN} -g ${BINGRP} -m 444 \
	    ${.ALLSRC} ${DESTDIR}${CLANG_INTR_INCDIR}

arm_neon.h: ${CLANG_INC}/clang/Basic/arm_neon.td
	${TBLGEN} -gen-arm-neon -o ${.TARGET} ${.ALLSRC}

.include <bsd.obj.mk>
