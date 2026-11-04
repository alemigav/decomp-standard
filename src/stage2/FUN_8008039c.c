/* FUN_8008039c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008039c  body 0x8008039c..0x800804d3  size 312 B
 * body sha256 fd9704a83861b01cd52bb9b82559e991e98cc9f3c90dadbd2b307698cc755d93
 * provider record sha256 4db9e3cfaaf11f6b3483f27460d6cb2e259b829236ffb834d8b78fa680122d48
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8008039c(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        param_1[1] = 0x1000000;
        *(undefined1 *)((int)param_1 + 0x26f) = 0;
        *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    param_1[0x7a] = ((*(byte *)((int)param_1 + 5) & 1) + 3) * 0x1000000 + 0x300;
    *(ushort *)(param_1 + 0x78) = (*(byte *)((int)param_1 + 5) & 1) * 400 + -200;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    FUN_80077d18(0,param_1);
    *param_1 = *param_1 & 0xfffffffb;
  }
  if (*(char *)((int)param_1 + 0x1ea) != '\0') {
    FUN_80032b5c(param_1,0);
  }
  cVar2 = FUN_80089d54(param_1,param_2,param_3,0x400);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  return;
}
