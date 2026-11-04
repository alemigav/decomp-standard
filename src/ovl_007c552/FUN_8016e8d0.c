/* FUN_8016e8d0
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016e8d0  body 0x8016e8d0..0x8016eb73  size 676 B
 * body sha256 5e9087d40704e14827c31fb82f281a8cb968154d4b50eb3f949a9fbb134e5bf5
 * provider record sha256 0f5031273459a40c25170d89400136f29d09ccb3d938cf7f0cd923be79410dc6
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016e8d0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  func_0x80026980(0);
  func_0x80077430(0xb4,0x18);
  _DAT_800e90f8 = 1;
  _DAT_800e110c = _DAT_800e110c & 0xffffffef;
  func_0x800274e4(2);
  DAT_800e9183 = 0;
  func_0x80052bbc(0xf01c,0x803);
  func_0x800428e0(200);
  DAT_800e9182 = 0;
  DAT_80171dda = 0;
  _DAT_800df934 = _DAT_800c52d8 + 0x10007U & 0xfffffff8;
  iVar3 = func_0x800479c8(_DAT_800df934,&DAT_80171d68,0x15be,1);
  _DAT_800df934 = iVar3 + 7U & 0xfffffff8;
  iVar3 = func_0x800479c8(_DAT_800df934,&DAT_80171d84,0x15bf,1);
  _DAT_800df934 = iVar3 + 7U & 0xfffffff8;
  iVar3 = func_0x800479c8(_DAT_800df934,&DAT_80171da0,0x15c0,1);
  _DAT_800df934 = iVar3 + 7U & 0xfffffff8;
  iVar3 = func_0x800479c8(_DAT_800df934,&DAT_80171dbc,0x15c1,1);
  _DAT_800df934 = iVar3 + 7U & 0xfffffff8;
  DAT_800e1125 = 0x10;
  DAT_800e1124 = 8;
  DAT_80171dd4 = 0;
  DAT_80171db8 = 0;
  DAT_80171d9c = 0;
  iVar3 = func_0x80004cfc(0x758,_DAT_800df934,1,"ROOM800_SND_LD");
  DAT_80171dfe = 0;
  _DAT_800df92c = &DAT_80171df8;
  DAT_80171e00 = _DAT_800df934;
  _DAT_800df934 = _DAT_800df934 + iVar3;
  func_0x80076314();
  DAT_80171dd9 = 1;
  if ((_DAT_800e110c & 0x2000000) == 0) {
    DAT_80171ddb = 0;
  }
  else {
    DAT_80171ddb = 0x11;
  }
  DAT_80171de8 = 0;
  DAT_80171df4 = 0x2000;
  DAT_80171dec = 0;
  puVar1 = (undefined4 *)&DAT_800e8b30;
  puVar2 = &DAT_80171e80;
  do {
    puVar5 = puVar2;
    puVar4 = puVar1;
    uVar6 = puVar4[1];
    uVar7 = puVar4[2];
    uVar8 = puVar4[3];
    *puVar5 = *puVar4;
    puVar5[1] = uVar6;
    puVar5[2] = uVar7;
    puVar5[3] = uVar8;
    puVar1 = puVar4 + 4;
    puVar2 = puVar5 + 4;
  } while (puVar4 + 4 != (undefined4 *)&DAT_800e9010);
  DAT_80171ddc = 0;
  DAT_80171dde = 0;
  DAT_80171ddf = 0;
  uVar6 = puVar4[5];
  uVar7 = puVar4[6];
  puVar5[4] = _DAT_800e9010;
  puVar5[5] = uVar6;
  puVar5[6] = uVar7;
  DAT_80171de0 = 0;
  FUN_80170104();
  return;
}
