/* FUN_8000a900
 * image   boot (boot), base 0x80000480
 * address 0x8000a900  body 0x8000a900..0x8000aa0f  size 272 B
 * body sha256 e65f2156cdd97efb69bb09bb9d067bcb293068bbb05c621548993ca292ce12d8
 * provider record sha256 1c27b5d6197c622b4c369917512e53dca8dd069b077a49aa59af6fdfa46b01c5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000a900(uint *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  byte bVar5;
  int iVar6;
  short asStack_120 [128];
  
  iVar6 = 0;
  if ((*param_1 & 1) == 0) {
    iVar1 = 5;
  }
  else {
    iVar2 = FUN_8000a2d0(param_1);
    iVar1 = 2;
    if (iVar2 != 2) {
      bVar5 = 0;
      if (*(char *)(param_1 + 0x19) != '\0') {
        do {
          iVar2 = FUN_8000a394(param_1,asStack_120,0,bVar5);
          if (iVar2 != 0) {
            return iVar2;
          }
          uVar3 = 1;
          if (bVar5 == 0) {
            uVar3 = param_1[0x18];
          }
          if ((int)uVar3 < 0x80) {
            psVar4 = asStack_120 + uVar3;
            do {
              uVar3 = uVar3 + 1;
              iVar6 = iVar6 + (uint)(*psVar4 == 3);
              psVar4 = psVar4 + 1;
            } while ((int)uVar3 < 0x80);
          }
          bVar5 = bVar5 + 1;
        } while (bVar5 < *(byte *)(param_1 + 0x19));
      }
      *param_2 = iVar6 << 8;
      iVar1 = 0;
    }
  }
  return iVar1;
}
