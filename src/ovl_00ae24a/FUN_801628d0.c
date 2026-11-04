/* FUN_801628d0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801628d0  body 0x801628d0..0x80162ca3  size 980 B
 * body sha256 c6f69a67b454d1b64f7d5b928f71aece710aeb97895cd6962232ed0b7b27754f
 * provider record sha256 e063ac079439505226400a37275d6e9c2f8905bc6d82911bcd260618e8c8474a
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801628d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = 0x20103;
  local_24 = 0x1020300;
  local_20 = 0x3000201;
  local_1c = 0x3010200;
  bVar1 = *(byte *)(param_1 + 6);
  *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) | 2;
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x2001f00;
        *(undefined1 *)(param_1 + 6) = 3;
        func_0x80077d18(10,param_1);
      }
      else if (bVar1 != 3) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x80);
      cVar4 = *(char *)(param_1 + 0x1e9);
      if (cVar4 == 'U') {
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        *(ushort *)(param_1 + 0x2c2) = *(ushort *)(param_1 + 0x2c2) & 0xfffd;
        cVar4 = *(char *)(param_1 + 0x1e9);
      }
      if (cVar4 == '\x19') {
        FUN_801667c0(*(undefined1 *)(&local_28 + *(char *)(param_1 + 0x207)),0x90b01);
        FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 2),0x90b01);
        func_0x80077d18(9,param_1);
      }
      if (*(char *)(param_1 + 0x1e9) == '\x0f') {
        FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 1),0x90b01);
        FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 3),0x90b01);
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x5001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    FUN_8016676c(0xb01);
    func_0x80077d18(10,param_1);
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    *(byte *)(param_1 + 0x207) = (byte)((int)(uVar2 & 0xff) >> (uVar3 & 3)) & 3;
  }
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    FUN_801667c0(*(undefined1 *)(&local_28 + *(char *)(param_1 + 0x207)),0xb01);
  }
  cVar4 = *(char *)(param_1 + 0x1e9);
  if (cVar4 == '\a') {
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 1),0xb01);
    cVar4 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar4 == '\n') {
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 2),0xb01);
  }
  cVar4 = *(char *)(param_1 + 0x1e9);
  if (cVar4 == '\x0f') {
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 3),0xb01);
    cVar4 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar4 == '7') {
    FUN_801667c0(*(undefined1 *)(&local_28 + *(char *)(param_1 + 0x207)),0x70b01);
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 2),0x70b01);
    func_0x80077d18(9,param_1);
  }
  cVar4 = *(char *)(param_1 + 0x1e9);
  if (cVar4 == '=') {
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 1),0x70b01);
    FUN_801667c0(*(undefined1 *)((int)&local_28 + *(char *)(param_1 + 0x207) * 4 + 3),0x70b01);
    cVar4 = *(char *)(param_1 + 0x1e9);
  }
  if (cVar4 == 'Z') {
    func_0x80077d18(0xb,param_1);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + (*(short *)(param_1 + 0x1e0) >> 1);
  cVar4 = func_0x80089d54(param_1,param_2,param_3,0x80);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
  if (*(int *)(param_1 + 0x28) < 12000) {
    func_0x80032b5c(param_1,0);
  }
  return;
}
