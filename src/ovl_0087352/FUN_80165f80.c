/* FUN_80165f80
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165f80  body 0x80165f80..0x80165fef  size 112 B
 * body sha256 1422ce7f7dca4ffeee4ca473d863629f5efffc08698c985f6d73ef440c2cbece
 * provider record sha256 c0d1a430ea8d77826ac6f321a508a800a904d1ebe7d5bfd4688e4b02add517b4
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165f80(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  
  if ((*(ushort *)(param_1 + 0x2c6) & 0x10) != 0) {
    FUN_80166294(param_1,0x15e);
    bVar1 = func_0x80033604();
    *(byte *)(param_1 + 700) = bVar1 & 0x9d;
    uVar2 = func_0x80065628();
    *(undefined1 *)(param_1 + 699) = uVar2;
    *(undefined1 *)(param_1 + 0x2b8) = 0x1e;
    FUN_80165c68(param_1,4);
    *(ushort *)(param_1 + 0x2c6) = *(ushort *)(param_1 + 0x2c6) & 0xffa7;
  }
  return;
}
