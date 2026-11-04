/* FUN_8000b374
 * image   boot (boot), base 0x80000480
 * address 0x8000b374  body 0x8000b374..0x8000b4db  size 360 B
 * body sha256 60c57fe62bb21874d4108fdf6925a04c2978ebdd04f92e7db05ebbc87595fff5
 * provider record sha256 c24a18496982dde2a0f9506ecf9faccd8428a1bff4cf9732454f47db0d299b98
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8000b374(int param_1,int param_2,int param_3)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  
  bVar7 = 0;
  iVar6 = 0;
  uVar3 = param_2 >> 0x10 & 0xffff;
  uVar4 = uVar3 >> 8;
  if (*(char *)(param_1 + 100) != '\0') {
    uVar5 = 0;
    do {
      iVar8 = 1;
      if (uVar5 == 0) {
        iVar8 = *(int *)(param_1 + 0x60);
      }
      if ((uVar5 == uVar4) ||
         (((int)(uint)*(byte *)(param_3 + ((param_2 >> 0x10 & 0xffU) >> 2) + (uVar4 & 7) * 0x20 +
                               0x101) >> (uVar5 & 7) & 1U) != 0)) {
        if (uVar5 != *(byte *)(param_3 + 0x100)) {
          iVar1 = FUN_8000a394(param_1,param_3,0);
          if (iVar1 != 0 && iVar1 != 3) {
            return iVar1;
          }
          *(byte *)(param_3 + 0x100) = bVar7;
        }
        if (iVar6 < 2 && iVar8 < 0x80) {
          puVar2 = (ushort *)(iVar8 * 2 + param_3);
          do {
            iVar8 = iVar8 + 1;
            iVar6 = iVar6 + (uint)(*puVar2 == uVar3);
            puVar2 = puVar2 + 1;
          } while (iVar6 < 2 && iVar8 < 0x80);
        }
        if (1 < iVar6) {
          return 2;
        }
      }
      bVar7 = bVar7 + 1;
      uVar5 = (uint)bVar7;
    } while (bVar7 < *(byte *)(param_1 + 100));
  }
  return iVar6;
}
