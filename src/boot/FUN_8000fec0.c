/* FUN_8000fec0
 * image   boot (boot), base 0x80000480
 * address 0x8000fec0  body 0x8000fec0..0x8000ff57  size 152 B
 * body sha256 7ffbc88b4b1bddd2ccfaf9252a95f2c71e65007ee71ea78d7b22cb426e9600af
 * provider record sha256 2babfd3d5876eab3fac2dfeab8386453f1eb71770ae44dce0d9e103dd10e9718
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000ff4c) */

undefined4 FUN_8000fec0(short *param_1,ushort *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (*param_2 & 0x7ff0) >> 4;
  if (uVar2 == 0x7ff) {
    *param_1 = 0;
    uVar1 = 2;
    if (((((*param_2 & 0xf) == 0) && (uVar1 = 2, param_2[1] == 0)) && (uVar1 = 2, param_2[2] == 0))
       && (uVar1 = 2, param_2[3] == 0)) {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0xffffffff;
    if (uVar2 == 0) {
      uVar1 = 0;
      *param_1 = 0;
    }
    else {
      *param_2 = *param_2 & 0x800f | 0x3ff0;
      *param_1 = (short)uVar2 + -0x3fe;
    }
  }
  return uVar1;
}
