/* FUN_800804d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800804d4  body 0x800804d4..0x800805d7  size 260 B
 * body sha256 f55f389f489388e6f2ec2f8df123ec9291fda56fbf2105ba0a5f9aa20ca821a7
 * provider record sha256 62cea4ca1a7b9bc20699d5c9c43d67fdba7ae324233e49f3e15afcd9ae0ef2d2
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800804d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
      }
      goto LAB_800805a8;
    }
    if (bVar1 != 0) goto LAB_800805a8;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    FUN_80077d18(3,param_1);
    DAT_800e10ec = DAT_800e10ec | 0x4000000;
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x200);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
LAB_800805a8:
  if (*(char *)(param_1 + 0x1ea) == '\0') {
    FUN_80033680(param_1,0,1);
  }
  return;
}
