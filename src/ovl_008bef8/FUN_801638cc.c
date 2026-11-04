/* FUN_801638cc
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801638cc  body 0x801638cc..0x801639f3  size 296 B
 * body sha256 1a76bb49ff2236de7d00819630ce04c410e96f57c2cb1bde0aabc54c467f18cb
 * provider record sha256 f53e56d30f9646847ceb8d2392c663847a9ade1561034e055ffbb19c5f5c5a70
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801638cc(int param_1)

{
  undefined1 uVar2;
  uint uVar1;
  byte bVar3;
  
  if (*(short *)(param_1 + 0x1f2) < 25000) {
    *(ushort *)(param_1 + 0x2b4) = *(ushort *)(param_1 + 0x2b4) | 0x20;
  }
  if (_DAT_800e1322 < 0) {
    *(undefined1 *)(param_1 + 0x26e) = 0;
  }
  else if (*(char *)(param_1 + 0x2c2) == '\a') {
    if (*(char *)(param_1 + 0x2cc) == '\x01') {
      *(undefined1 *)(param_1 + 0x26e) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 1;
    }
  }
  else if ((((*(ushort *)(param_1 + 0x2b4) & 0x10) == 0) || (_DAT_800e8cac != 8)) ||
          (24999 < *(short *)(param_1 + 0x1f2))) {
    if (*(char *)(param_1 + 0x2c1) == '\0') {
      if (*(char *)(param_1 + 0x2ca) == '\0') {
        uVar1 = func_0x80033604();
        if ((uVar1 & 3) == 0) {
          *(undefined1 *)(param_1 + 0x26e) = 4;
          bVar3 = func_0x80033604();
          *(byte *)(param_1 + 0x2ca) = (bVar3 & 0x3f) + 0x78;
        }
        else {
          *(undefined1 *)(param_1 + 0x26e) = 0;
        }
      }
      else {
        *(undefined1 *)(param_1 + 0x26e) = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 0;
    }
  }
  else {
    uVar2 = 3;
    if ((_DAT_800e110c & 0x40000000) == 0) {
      uVar2 = 2;
    }
    else {
      *(undefined2 *)(param_1 + 0x2c4) = 0;
      *(undefined2 *)(param_1 + 0x2c6) = 0;
    }
    *(undefined1 *)(param_1 + 0x2c0) = 0;
    *(undefined1 *)(param_1 + 0x26e) = uVar2;
  }
  return;
}
