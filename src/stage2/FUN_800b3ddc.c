/* FUN_800b3ddc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b3ddc  body 0x800b3ddc..0x800b3f53  size 376 B
 * body sha256 6139ca80c72a1fb831bb45f02cd61aea752f39cbf4fff793ce35c100917fc728
 * provider record sha256 dda5560897a73213f7ae9fc958e14a95f8a501dfac8dd235a3296f95c2d7befe
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
ulonglong FUN_800b3ddc(int param_1,undefined4 *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong in_f0_1;
  float fVar5;
  
  uVar4 = (undefined4)(in_f0_1 >> 0x20);
  if ((param_1 != -1) && (uVar3 = 0, DAT_80136d80 != '\0')) {
    iVar2 = -0x7fea74e0;
    do {
      if ((*(char *)(iVar2 + 0x1200) != '\0') && (*(int *)(iVar2 + 0x1224) == param_1))
      goto LAB_800b3e48;
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x1228;
    } while (uVar3 < 2);
    uVar3 = 0xffffffff;
LAB_800b3e48:
    if (uVar3 != 0xffffffff) {
      osRecvMesg(0x8015afa0,0,1);
      iVar2 = uVar3 * 0x1228;
      if ((&DAT_80159d20)[iVar2] == '\x02') {
        fVar5 = (float)*(int *)(iVar2 + -0x7fea62c4);
        if (*(int *)(iVar2 + -0x7fea62c4) < 0) {
          uVar4 = 0x41f00000;
          fVar5 = fVar5 + 4.2949673e+09;
        }
        fVar1 = (float)*(int *)(iVar2 + -0x7fea62d8);
        if (*(int *)(iVar2 + -0x7fea62d8) < 0) {
          uVar4 = 0x41f00000;
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar5 = fVar5 / fVar1;
      }
      else {
        fVar5 = 0.0;
      }
      *param_2 = *(undefined4 *)(uVar3 * 0x1228 + -0x7fea62c0);
      osSendMesg(0x8015afa0,0,0);
      return CONCAT44(uVar4,fVar5);
    }
  }
  return in_f0_1 & 0xffffffff00000000;
}
