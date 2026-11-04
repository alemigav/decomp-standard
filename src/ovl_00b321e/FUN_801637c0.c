/* FUN_801637c0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801637c0  body 0x801637c0..0x80163a0f  size 592 B
 * body sha256 ab1fcf726bfabcd7daa5ec961d3a845e21f8af7915924e202e580ce3319721d9
 * provider record sha256 b249a4f7a3b53b3b126354773817088ef7145635a2327eb3837dba93824bde5d
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801637c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  ushort uVar5;
  int iVar4;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  short local_40;
  short local_3e;
  short local_3c;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      if (*(int *)(param_1 + 0x2c) < (int)*(short *)(param_1 + 0x25e)) {
        *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 0x6f;
      }
      iVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
      if (iVar4 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 700) = 0;
      *(undefined1 *)(param_1 + 5) = 1;
      *(undefined2 *)(param_1 + 6) = 0;
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1f6) = 6;
    *(undefined1 *)(param_1 + 0x206) = 0xf;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined1 *)(param_1 + 700) = 1;
    *(undefined1 *)(param_1 + 0x207) = 0xf8;
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
    *(undefined2 *)(param_1 + 100) = 0;
    FUN_80162564(param_1);
  }
  if (*(char *)(param_1 + 7) == '\0') {
    iVar4 = *(int *)(param_1 + 0x2c) + -0x6f;
    *(int *)(param_1 + 0x2c) = iVar4;
    if (iVar4 <= *(short *)(param_1 + 0x25e) + -0x30f) {
      *(undefined1 *)(param_1 + 7) = 1;
    }
  }
  else {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (int)*(char *)(param_1 + 0x207);
    if ((*(char *)(param_1 + 0x206) == '\x0f') || (*(char *)(param_1 + 0x206) == '\a')) {
      func_0x80077d18(5,param_1);
    }
    cVar2 = *(char *)(param_1 + 0x206);
    *(char *)(param_1 + 0x206) = cVar2 + -1;
    if (cVar2 == '\x01') {
      *(undefined1 *)(param_1 + 0x206) = 0xf;
      sVar3 = *(short *)(param_1 + 0x1f6);
      *(short *)(param_1 + 0x1f6) = sVar3 + -1;
      *(char *)(param_1 + 0x207) = -*(char *)(param_1 + 0x207);
      if (sVar3 == 1) {
        *(undefined1 *)(param_1 + 6) = 2;
        *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
      }
    }
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  if (*(short *)(param_1 + 0x1f6) < 6) {
    local_48 = *(undefined2 *)(param_1 + 0x2a);
    local_46 = *(undefined2 *)(param_1 + 0x2e);
    local_44 = *(undefined2 *)(param_1 + 0x32);
    uVar5 = func_0x80033604();
    local_40 = (uVar5 & 0xff) * -0x10 + 0x400;
    uVar5 = func_0x80033604();
    local_3e = *(short *)(param_1 + 0x25e) - ((uVar5 & 0x1f) * 8 + 0x32);
    uVar5 = func_0x80033604();
    local_3c = (uVar5 & 0xff) * 0x10 + -0x600;
    FUN_801664b0(param_1,5,&local_48,&local_40);
  }
  return;
}
