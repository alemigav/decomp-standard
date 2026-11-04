/* FUN_801643d0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801643d0  body 0x801643d0..0x8016452f  size 352 B
 * body sha256 4d45af478135ceabac831d6a3a94f7e80090807533a8bcc61116c71c5fe8c07b
 * provider record sha256 61b5d30688e1f4fcfc35336906753052186337a5450bc4fadb37b7a6bb6c3c8d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801643d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar4;
  int iVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
    uVar3 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uint)(byte)(&DAT_80166ddc)[uVar3 & 7] * 0x1000000 + 0xf00;
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = (bVar4 & 3) + 1;
  }
  else if (*(char *)(param_1 + 7) != '\x01') goto LAB_80164510;
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar2 != 0) {
    cVar1 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar1 + -1;
    if (cVar1 == '\x01') {
      *(undefined2 *)(param_1 + 6) = 0x100;
    }
    else {
      uVar3 = func_0x80033604();
      *(uint *)(param_1 + 0x1e8) = (uint)(byte)(&DAT_80166ddc)[uVar3 & 7] * 0x1000000 + 0xf00;
    }
  }
  if (*(char *)(param_1 + 0x1e8) == '\v') {
    func_0x80032b5c(param_1,0);
  }
LAB_80164510:
  func_0x80033648(param_1);
  return;
}
