/* FUN_801626fc
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801626fc  body 0x801626fc..0x8016285b  size 352 B
 * body sha256 1843cf9f0c20cc6c3f6a8abc0d86cd03a3ec471c90f18a8f1ce67fd3a24ee83b
 * provider record sha256 f5ccac6b8fdb3c08c27ef174d567ae9578529a8bb77343ed469057b64781bedf
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801626fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  short sVar5;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = (undefined1  [4])0x80;
  local_18 = 3;
  local_14 = 0x20;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    iVar2 = *(int *)(local_1c + ((*(byte *)(param_1 + 5) - 5) * 4 + -3) * 2 + 2);
    *(undefined1 *)(param_1 + 6) = 1;
    *(int *)(param_1 + 0x1e8) = iVar2 * 0x1000000 + 0x300;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 0x1f6) = (uVar3 & 0x1f) + 0x3c;
  }
  sVar4 = FUN_80166b04(param_1,(int)*(short *)(local_1c + (*(byte *)(param_1 + 5) - 5) * 8 + 2));
  sVar5 = *(short *)(param_1 + 0x1f6) + -1;
  *(short *)(param_1 + 0x1f6) = sVar5;
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar4;
  if ((sVar5 == -1) || (sVar4 == 0)) {
    *(undefined1 *)(param_1 + 6) = 2;
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  FUN_80167938(param_1);
  return;
}
