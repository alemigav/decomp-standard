/* FUN_80169060
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80169060  body 0x80169060..0x8016922b  size 460 B
 * body sha256 dd2e57cbe6218ac81919e72019b540988745eea75e45f3cd9bf061d629f43d89
 * provider record sha256 2ce034111df7397e0c0cf9a11ff7dda350580a4309ca9d7b83e86f9eef6b94e0
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80169060(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  uVar4 = 0xfa;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined2 *)(param_1 + 0x1aa) = 1;
        *(undefined4 *)(param_1 + 4) = 0x1000000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar2 & 7) * 0x10000 + 0x6000300;
    *(undefined1 *)(param_1 + 6) = 1;
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    func_0x80037780(6000,0,*(int *)(param_1 + 0x234) + 0x38,&local_20);
    if (*(char *)(param_1 + 0x2d5) == '\0') {
      func_0x80077d18(0xc,param_1);
      *(undefined1 *)(param_1 + 0x2d5) = 0x96;
    }
    cVar3 = *(char *)(param_1 + 5);
    if ((cVar3 == '\n') && ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0)) {
      FUN_80167910(param_1);
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x800;
      cVar3 = *(char *)(param_1 + 5);
    }
    if (cVar3 == '\v') {
      FUN_80167abc(param_1);
    }
    cVar3 = *(char *)(param_1 + 5);
    if (cVar3 == '\x0e') {
      FUN_80167c88(param_1);
      cVar3 = *(char *)(param_1 + 5);
    }
    if (cVar3 == '\x10') {
      if (((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) && (8 < *(byte *)(param_1 + 0x2d6))) {
        FUN_80167910(param_1);
        *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) | 0x800;
      }
      *(char *)(param_1 + 0x2d6) = *(char *)(param_1 + 0x2d6) + '\x01';
    }
  }
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x400,uVar4);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  return;
}
