/* FUN_80164e88
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80164e88  body 0x80164e88..0x80164fc7  size 320 B
 * body sha256 1444b3e38a588c60ac80cf4e9526d692c0e218b7bbecc6180894b7706e1d443a
 * provider record sha256 7937f203332c1cbf12f4eb5ad7a0a36c99951be750e0b88a6e5ca75e07c31976
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164e88(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 0x2d9) == '\0') {
    *(undefined1 *)(param_1 + 0x2c1) = 6;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  cVar1 = '\x01';
  if (*(char *)(param_1 + 5) != '\x01') {
    if (((uint)*(byte *)(param_1 + 0x26e) % 3 == 0) && (*(char *)(param_1 + 0x2d9) == '\0')) {
      uVar2 = func_0x80033604(param_1);
      uVar2 = (uVar2 & 1) << 2 | 3;
    }
    else {
      uVar2 = 10;
    }
    FUN_80166b98(param_1,uVar2,1);
    cVar1 = *(char *)(param_1 + 5);
  }
  if (cVar1 != '\x10') {
    func_0x80077d18(2,param_1);
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  if (*(byte *)(param_1 + 0x2ca) == 0) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2c1) = 3;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else {
    *(uint *)(param_1 + 4) =
         (uint)*(byte *)(param_1 + 0x2ca) * 0x10000 + (uint)*(byte *)(param_1 + 0x2cb) * 0x100 +
         (uint)*(byte *)(param_1 + 0x2cc) + 0x1000000;
  }
  return;
}
