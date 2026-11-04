/* FUN_8000efa0
 * image   boot (boot), base 0x80000480
 * address 0x8000efa0  body 0x8000efa0..0x8000f013  size 116 B
 * body sha256 2ed304267c3068d0a489e7c5e96b4676619e94b124ce3e683815a5cea1c93561
 * provider record sha256 efc5ab5539e1d87565aca6f8c549eef1f88757df5818c4d5b7e06e61251be7bd
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8000efa0(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  
  if (0 < (int)param_2) {
    if (0x1fff < param_2) {
      puVar3 = (undefined *)0x80000000;
      do {
        cacheOp(1,puVar3);
        bVar1 = puVar3 < &UNK_80001ff0;
        puVar3 = puVar3 + 0x10;
      } while (bVar1);
      return;
    }
    if (param_1 < param_1 + param_2) {
      uVar2 = param_1 - (param_1 & 0xf);
      do {
        cacheOp(0x19,uVar2);
        bVar1 = uVar2 < (param_1 + param_2) - 0x10;
        uVar2 = uVar2 + 0x10;
      } while (bVar1);
    }
  }
  return;
}
