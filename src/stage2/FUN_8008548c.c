/* FUN_8008548c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008548c  body 0x8008548c..0x800855d7  size 332 B
 * body sha256 306dbe157c698714697468ad023b2ebfd752d44f13ac1a0870062099edb8f375
 * provider record sha256 525b49cbdb9fa85910b282f9d4a7e6f5d751b793dc69cd53bd93fd308dc0b3b9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008548c(uint *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  short *psVar6;
  int iVar7;
  uint uVar8;
  
  uVar1 = DAT_80124830;
  iVar7 = *(int *)param_1[0x32];
  if ((((*param_1 & 8) == 0) || (iVar2 = ((int *)param_1[0x32])[2], iVar2 == 0)) ||
     (*(int *)(param_2 + 0x48) == 0)) {
    iVar2 = *(int *)(param_1[0x32] + 4);
  }
  psVar6 = (short *)(iVar2 + 0xc);
  uVar8 = DAT_80124830 | 0x10;
  while (iVar7 = iVar7 + -1, iVar7 != -1) {
    puVar5 = &DAT_8012487c;
    if (-1 < *(int *)(*(int *)(psVar6 + -2) + 8)) {
      if ((param_1[0x2b] != 0) &&
         (uVar3 = *(uint *)(*(int *)(*(int *)(psVar6 + -2) + 8) * 4 + param_1[0x2b]),
         puVar5 = &DAT_8012487c + (uVar3 & 0x7f) * 4, uVar3 != *puVar5)) {
        trap(0);
      }
    }
    iVar4 = DAT_80124860 * 0x1c;
    DAT_80124860 = DAT_80124860 + 1;
    *(uint *)(&DAT_80125080 + iVar4) = puVar5[2];
    puVar5[2] = (uint)(&DAT_8012507c + iVar4);
    *(int *)(&DAT_8012507c + iVar4) = iVar2;
    *(int *)(&DAT_80125084 + iVar4) = param_2;
    *(uint **)(&DAT_80125088 + iVar4) = param_1 + 0x1a;
    if ((*param_1 & 8) == 0) {
      *(undefined4 *)(&DAT_8012508c + iVar4) = 0;
    }
    else if (*(int *)(param_1[0x32] + 8) == 0) {
      *(undefined4 *)(&DAT_8012508c + iVar4) = 0;
    }
    else if (*(int *)(param_2 + 0x48) == 0) {
      *(undefined4 *)(&DAT_8012508c + iVar4) = 0;
    }
    else {
      *(int *)(&DAT_8012508c + iVar4) = *(int *)(param_2 + 0x48) + *psVar6 * 0x10;
    }
    if (param_1[0x33] - 1 < 0xfffffffe) {
      *(uint *)(&DAT_80125090 + iVar4) = uVar8;
    }
    else {
      *(uint *)(&DAT_80125090 + iVar4) = uVar1;
    }
    *(undefined4 *)(&DAT_80125094 + iVar4) = param_3;
    psVar6 = psVar6 + 8;
    iVar2 = iVar2 + 0x10;
  }
  return;
}
