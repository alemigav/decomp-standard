/* FUN_80166a44
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166a44  body 0x80166a44..0x80166b97  size 340 B
 * body sha256 458b300e38039023a1f0dd4f5822c8e9083a331ffd896c098cbd82fe156047dd
 * provider record sha256 4dfcbd1d719136c059b53346e43a934f34975ed3e955af7a24fb112175f4b7f9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80166a44(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar3 = &DAT_800e1130;
  }
  else {
    puVar3 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar4 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  iVar1 = func_0x80032e74(param_1,*(undefined4 *)(puVar3 + 0x28),*(undefined4 *)(puVar3 + 0x30),
                          0x100);
  func_0x80032e74(param_1,*(undefined4 *)(puVar3 + 0x28),*(undefined4 *)(puVar3 + 0x30),0x700);
  if (-1 < *(short *)(puVar3 + 0x1f2)) {
    if ((int)uVar4 < 0x5dd) {
      if (*(char *)(param_1 + 0x2bf) == '\0') {
        iVar2 = 2;
        if (iVar1 << 0x10 < 0) {
          iVar2 = 1;
        }
        if (*(char *)(iVar2 + param_1 + 0x2b4 + 0x21) != '\0') {
          return 0;
        }
        if ((_DAT_800e1128 & 0x80) == 0) {
          *(char *)(param_1 + 0x2c3) = (char)iVar2;
          *(undefined1 *)(param_1 + 0x2c1) = 4;
          *(undefined1 *)(iVar2 + param_1 + 0x2b4 + 0x21) = 0xf;
          return 1;
        }
        return 0;
      }
      *(char *)(param_1 + 0x2bf) = *(char *)(param_1 + 0x2bf) + -1;
    }
    else {
      *(undefined1 *)(param_1 + 0x2bf) = 0x5a;
    }
  }
  return 0;
}
