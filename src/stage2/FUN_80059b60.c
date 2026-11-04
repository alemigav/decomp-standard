/* FUN_80059b60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059b60  body 0x80059b60..0x80059c7b  size 284 B
 * body sha256 bb0fc07565e59b3819f73b6ab2b3e08183e94543a9723262a9c6435b8766a2fa
 * provider record sha256 70607c1be007133555c66f811b45ed85dddd271687fddf2e9fc1f39075d164a8
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059b60(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x7000000;
      }
      goto LAB_80059c48;
    }
    if (bVar1 != 0) goto LAB_80059c48;
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000700;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    FUN_80077adc(0x4030001,param_1 + 0x28);
    *(undefined1 *)(param_1 + 0x25c) = 1;
    FUN_80052bd0(3,0);
    FUN_80052c6c(8,200,0);
    FUN_80052d10(0x5a,200,0,8);
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x200);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
LAB_80059c48:
  if (*(char *)(param_1 + 0x1ea) == '\0') {
    FUN_80033680(param_1,0,1);
  }
  return;
}
