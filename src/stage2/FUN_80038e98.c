/* FUN_80038e98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80038e98  body 0x80038e98..0x80038f3f  size 168 B
 * body sha256 45bacd06cc817edc10960b48ca6c826d0a5ca7cdb0b863a7beb6fc64a02293b5
 * provider record sha256 40c7c181ac2d3c7e037cd4e771e9aaa9d892c941da67b3db6bdc0f8dc14db499
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80038e98(char param_1,char param_2,int param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    puVar1 = &DAT_800ebda8;
    do {
      uVar2 = uVar2 + 1;
      if ((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) {
        puVar1[1] = 0;
        *puVar1 = 0;
        *(undefined2 *)(puVar1 + 0x18) = 0;
      }
      puVar1 = puVar1 + 0x7c;
    } while (uVar2 < 0x60);
    return 0;
  }
  puVar1 = &DAT_800ebda8;
  do {
    if (((puVar1[0x1c] == param_1) && (puVar1[0x1e] == param_2)) &&
       (*(int *)(puVar1 + 0x6c) == param_3)) {
      puVar1[1] = 0;
      *puVar1 = 0;
      *(undefined2 *)(puVar1 + 0x18) = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 0x7c;
  } while (uVar2 < 0x60);
  return 0;
}
