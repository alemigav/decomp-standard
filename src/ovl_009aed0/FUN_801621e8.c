/* FUN_801621e8
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x801621e8  body 0x801621e8..0x801622f3  size 268 B
 * body sha256 8cd0b06a46032033809ac700dbe1ced1ba3ba7ff9d41f995ec092214f1c713bc
 * provider record sha256 cd305a31ecd8de0f847e4e7224673a604647b1ecf7057968e32730123c7889ed
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801621e8(int param_1,short param_2,short param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar5 = 0;
  puVar4 = &DAT_801662e0;
  do {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x234) + (uint)*puVar4 * 0x178);
    puVar3[0x13] = param_2 + 0x38d3 + puVar3[0x13];
    local_30 = puVar3[0x13];
    puVar3[0x15] = param_3 + 0x392c + puVar3[0x15];
    local_2c = 0;
    local_28 = puVar3[0x15];
    iVar2 = func_0x800667d4(&local_30,0,1 << (*(byte *)(param_1 + 0x1a2) & 0x1f),0x400);
    if (iVar2 != 0) {
      *puVar3 = 0;
    }
    uVar1 = *puVar4;
    puVar4 = puVar4 + 10;
    uVar5 = uVar5 + 1;
    FUN_80163068(param_1,uVar1,0x40,0x40,0x40);
  } while (uVar5 < 0xf);
  return;
}
