/* FUN_80165388
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165388  body 0x80165388..0x801654c3  size 316 B
 * body sha256 d00f505b15d1772597f1c98d7e20ac41c09911e43417a8d4aa5e2eaa6c6cecfc
 * provider record sha256 31aee1142085ffda1ba7db5e440c457a540ad4ec83f8e8ee8735e408ad4c1a3a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165388(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((*(char *)(param_1 + 5) == '\x0f') || (*(char *)(param_1 + 5) == '\x12')) {
    *(char *)(param_1 + 699) = *(char *)(param_1 + 699) + '\x03';
    uVar1 = func_0x80033604();
    if ((uVar1 & 3) == 0) {
      *(char *)(param_1 + 699) = *(char *)(param_1 + 699) + '\x01';
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      FUN_80166980(param_1,uVar1 & 0xf,uVar2 & 1 | 2);
    }
  }
  else {
    *(undefined1 *)(param_1 + 699) = 1;
    FUN_80166980(param_1,0,0);
    func_0x80077d18(1,param_1);
  }
  if ((*(byte *)(param_1 + 0x2bf) & 0x7f) == 1) {
    if (*(char *)(param_1 + 0x2b5) == '\0') {
      *(undefined2 *)(param_1 + 6) = 0x200;
    }
    else {
      *(undefined2 *)(param_1 + 6) = 0x100;
    }
  }
  else {
    *(undefined2 *)(param_1 + 6) = 0x301;
    if ((*(byte *)(param_1 + 0x2bf) & 0x40) == 0) {
      *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x1ea) * 0x100 + 0x12000000;
      func_0x80077d18(1,param_1);
      *(byte *)(param_1 + 0x2bf) = *(byte *)(param_1 + 0x2bf) | 0x40;
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x206) = 0;
    }
    *(undefined1 *)(param_1 + 700) = 1;
  }
  *(undefined2 *)(param_1 + 0x1f6) = 0;
  return;
}
