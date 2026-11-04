/* FUN_8005ea10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ea10  body 0x8005ea10..0x8005eb4f  size 320 B
 * body sha256 3abd6804ee67091d6fde47299b4de2b04f255e75cdd62e5db800cde8257452a0
 * provider record sha256 f6cc56aae12609d789d2989f2c49700bd728db7b5eddd69cee1efbde80b87681
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005ea10(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  cVar1 = *(char *)(param_1 + 0x1e9);
  if (cVar1 == '\x01') {
    local_18 = 0x78;
    local_16 = 0x4b0;
    local_14 = 0;
    iVar2 = *(int *)(param_1 + 0x234) + 0x1060;
    FUN_80037780(0x1002000,0,iVar2,&local_18);
    FUN_80037780(0x20c1000,(int)*(short *)(param_1 + 0x66),iVar2,&local_18);
    FUN_80037780(0x3081200,0,iVar2,&local_18);
    cVar1 = *(char *)(param_1 + 0x1e9);
  }
  if ((cVar1 == '\b') && (iVar2 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff), iVar2 == 0)) {
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  }
  cVar1 = '\n';
  if (*(char *)(param_1 + 0x1e8) == '\f') {
    cVar1 = '\t';
  }
  if (*(char *)(param_1 + 0x1e9) == cVar1) {
    FUN_8005c264(param_1);
    FUN_80052bd0(3,0);
    FUN_80052c6c(5,0x96,0x11);
  }
  if ((**(uint **)(param_1 + 0x214) & 0x100000) != 0) {
    FUN_80077adc(**(uint **)(param_1 + 0x214) & 0xf0000 | 0x1000001,param_1 + 0x28);
  }
  return;
}
