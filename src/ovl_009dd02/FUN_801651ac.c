/* FUN_801651ac
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801651ac  body 0x801651ac..0x80165277  size 204 B
 * body sha256 46196e596326ab561cf1446775aec00d731e059bde4187b20d2272909700f439
 * provider record sha256 542689221e04e2318ac72975ae1a57e4465a3f4f6f4cb8575c95dcfd23a29736
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801651ac(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x2d9) == '\0') {
    *(undefined1 *)(param_1 + 0x2c1) = 6;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  uVar1 = func_0x80033604();
  FUN_80166b98(param_1,(&DAT_8016733c)[uVar1 & 7],0);
  if (*(char *)(param_1 + 5) == '\x12') {
    uVar1 = func_0x80033604(2);
    FUN_80166b98(param_1,(&DAT_8016733c)[uVar1 & 7],1);
  }
  func_0x80077d18(2,param_1);
  *(uint *)(param_1 + 4) =
       (uint)*(byte *)(param_1 + 0x2ca) * 0x10000 + (uint)*(byte *)(param_1 + 0x2cb) * 0x100 +
       (uint)*(byte *)(param_1 + 0x2cc) + 0x1000000;
  return;
}
