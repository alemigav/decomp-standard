/* FUN_80009f8c
 * image   boot (boot), base 0x80000480
 * address 0x80009f8c  body 0x80009f8c..0x8000a0ef  size 356 B
 * body sha256 c2b1304b832eec94b87ee8f79981f21e6e888b5ea6bad15bf0862ec4ef176b3b
 * provider record sha256 e450eb48bfbd9bc2fd7fff26c4df01f9ae14d287466a78ec9a383dafd7b6cdbb
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80009f8c(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort local_30 [8];
  
  if (*(char *)(param_1 + 0x65) != '\0') {
    *(undefined1 *)(param_1 + 0x65) = 0;
    iVar2 = FUN_8000a66c();
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  iVar2 = 1;
  puVar6 = local_30;
  local_30[0] = 1;
  local_30[1] = 3;
  local_30[2] = 4;
  local_30[3] = 6;
  do {
    puVar6 = puVar6 + 1;
    iVar3 = FUN_800087a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),*puVar6,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
    local_30[5] = 0;
    local_30[4] = 0;
    puVar5 = param_2;
    do {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      local_30[4] = local_30[4] + uVar1;
      local_30[5] = local_30[5] + ~uVar1;
    } while (puVar5 < param_2 + 0xe);
  } while (((param_2[0xe] != local_30[4]) || (param_2[0xf] != local_30[5])) &&
          (iVar2 = iVar2 + 1, iVar2 < 4));
  iVar3 = 0;
  if (iVar2 == 4) {
    iVar2 = 10;
  }
  else {
    puVar6 = local_30;
    do {
      if ((iVar3 != iVar2) &&
         (iVar4 = FUN_80008b70(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),*puVar6,
                               param_2,1), iVar4 != 0)) {
        return iVar4;
      }
      iVar3 = iVar3 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar3 < 4);
    iVar2 = 0;
  }
  return iVar2;
}
