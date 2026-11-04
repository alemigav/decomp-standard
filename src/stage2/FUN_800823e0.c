/* FUN_800823e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800823e0  body 0x800823e0..0x80082473  size 148 B
 * body sha256 260083fe8d69db71e4a25ef8782f657c4a82f5580d62df5e8235f3cc067e313b
 * provider record sha256 42660c6eccab6f463347540f6a19ddc9af17bab3cfa682b75a79923309db2cf1
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800823e0(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)(DAT_801137f0 * DAT_801137f4) >> 1;
  puVar1 = DAT_8010b6e8;
  while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  if (DAT_8010b6ec != (undefined4 *)0x0) {
    uVar2 = (uint)(DAT_801137f0 * DAT_801137f4) >> 1;
    puVar1 = DAT_8010b6ec;
    while (uVar2 = uVar2 - 1, uVar2 != 0xffffffff) {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    }
  }
  return;
}
