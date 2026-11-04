/* FUN_8016288c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x8016288c  body 0x8016288c..0x8016291f  size 148 B
 * body sha256 228ed6d0478253ec8b28ad6d4e097ae85fb1c9a86a2c19fc1dc939eeb29ac343
 * provider record sha256 9fcd2f2dcbb080975c5f5df32c8dab9ae2a36e26ab49015ee34ad3b3c10d62a5
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016288c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 0x1f) * 0x10000 + 0x3f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,param_2,param_3,0x40);
  return;
}
