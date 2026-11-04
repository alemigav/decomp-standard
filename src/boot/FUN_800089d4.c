/* FUN_800089d4
 * image   boot (boot), base 0x80000480
 * address 0x800089d4  body 0x800089d4..0x80008b63  size 400 B
 * body sha256 65f88394be03dda5661acaad13a5ae18862b4406f959a7bce82cd79598472e07
 * provider record sha256 900635b19b48c099b03c82dff6b2a6c813922307135be83be556a01d61d2d382
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800089d4(int param_1,short param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 local_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  ushort local_44;
  undefined4 uStack_28;
  undefined1 local_23 [11];
  
  puVar9 = (undefined4 *)&DAT_80016470;
  _DAT_800164ac = 1;
  uStack_47 = 3;
  uStack_46 = 0x21;
  local_48 = 0xff;
  uStack_45 = 2;
  uVar1 = FUN_80008f30(param_2);
  iVar2 = 0x1f;
  puVar4 = local_23;
  local_44 = uVar1 & 0xff | param_2 << 5;
  local_23[1] = 0xff;
  do {
    *puVar4 = 0xff;
    iVar2 = iVar2 + -1;
    puVar4 = puVar4 + -1;
  } while (-1 < iVar2);
  if ((param_1 != 0) && (iVar2 = 0, 0 < param_1)) {
    do {
      *(undefined1 *)puVar9 = 0;
      iVar2 = iVar2 + 1;
      puVar9 = (undefined4 *)((int)puVar9 + 1);
    } while (iVar2 < param_1);
  }
  puVar7 = (undefined4 *)&local_48;
  puVar8 = puVar9;
  if (((uint)puVar9 & 3) == 0) {
    do {
      uVar3 = puVar7[1];
      uVar5 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar3;
      puVar8[2] = uVar5;
      puVar8[3] = uVar6;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (puVar7 != &uStack_28);
  }
  else {
    do {
      uVar3 = puVar7[1];
      uVar5 = puVar7[2];
      uVar6 = puVar7[3];
      *puVar8 = *puVar7;
      puVar8[1] = uVar3;
      puVar8[2] = uVar5;
      puVar8[3] = uVar6;
      puVar7 = puVar7 + 4;
      puVar8 = puVar8 + 4;
    } while (puVar7 != &uStack_28);
  }
  uVar3 = puVar7[1];
  *puVar8 = *puVar7;
  puVar8[1] = uVar3;
  *(undefined1 *)(puVar9 + 10) = 0xfe;
  return;
}
