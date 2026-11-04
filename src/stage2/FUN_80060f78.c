/* FUN_80060f78
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80060f78  body 0x80060f78..0x8006114b  size 468 B
 * body sha256 f3d0e7d5767b4662de9155236685b43aa9b9f5b8b96ed324db8f5495e1920065
 * provider record sha256 c8304d7a58a97fd03532a0e4197ae5dc5309c09f5b85740b1f355b777d43627f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_80060f78(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  
  puVar6 = (uint *)0x0;
  iVar5 = 0;
  iVar7 = 1;
  if ((DAT_800e110c & 0x10000000) != 0) {
    iVar7 = 2;
  }
  puVar4 = &DAT_800e13e8;
  do {
    puVar3 = (uint *)*puVar4;
    if (((((*puVar3 & 1) != 0) && (*(char *)((int)puVar3 + 0x26f) == '\0')) &&
        (-1 < *(short *)((int)puVar3 + 0x1f2))) &&
       ((((*(ushort *)((int)puVar3 + 0x1aa) & 0xc000) == 0 &&
         (*(ushort *)(puVar3 + 0x9b) = *(ushort *)(puVar3 + 0x9b) & 0xff00,
         (puVar3[0xb] + (int)*(short *)(puVar3 + 0x4d) + (uint)*(ushort *)((int)puVar3 + 0x13a)) -
         param_1[1] < (uint)*(ushort *)((int)puVar3 + 0x13a) << 1)) &&
        (uVar1 = FUN_80040bb4((*param_1 - puVar3[10]) * (*param_1 - puVar3[10]) +
                              (param_1[2] - puVar3[0xc]) * (param_1[2] - puVar3[0xc])),
        uVar1 < param_2)))) {
      puVar3[1] = 0x2000000;
      puVar6 = puVar3;
      if (iVar5 == 0) {
        iVar2 = FUN_80059e00(param_3,0);
        if (iVar2 == 2) {
          puVar3[1] = 0x3000000;
        }
      }
      else {
        *(short *)((int)puVar3 + 0x1f2) = *(short *)((int)puVar3 + 0x1f2) - (short)param_3;
        DAT_800e9010 = DAT_800e9010 - (short)param_3;
        if (*(short *)((int)puVar3 + 0x1f2) < 0) {
          puVar3[1] = 0x3000000;
        }
      }
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return puVar6;
}
