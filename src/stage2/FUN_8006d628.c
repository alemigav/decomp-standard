/* FUN_8006d628
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d628  body 0x8006d628..0x8006d717  size 240 B
 * body sha256 c9eaa46e7b4fdd118029a55358b81fdf4937c94e70b06efd2e80b8c61bfa70d3
 * provider record sha256 dea8cad7cbebb280f1211c0d17daecec3fb5b80b320cc387739243cd3c4e1257
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8006d660) */
/* WARNING: Removing unreachable block (ram,0x8006d664) */
/* WARNING: Removing unreachable block (ram,0x8006d66c) */
/* WARNING: Removing unreachable block (ram,0x8006d67c) */
/* WARNING: Removing unreachable block (ram,0x8006d680) */
/* WARNING: Removing unreachable block (ram,0x8006d688) */

void FUN_8006d628(uint param_1)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (DAT_80114f34 == '\0') {
    iVar4 = param_1 << 1;
    if (param_1 < 10) goto LAB_8006d6d4;
    param_1 = 2;
  }
  else {
    iVar4 = param_1 << 1;
    if (param_1 < 0xe) goto LAB_8006d6d4;
    param_1 = 10;
    puVar2 = &DAT_80114958;
    cVar1 = DAT_80114959;
    while (cVar1 != '\0') {
      if (param_1 == 0xd) {
        iVar4 = 0x1a;
        param_1 = 0xd;
        goto LAB_8006d6d4;
      }
      param_1 = param_1 + 1;
      if (0xd < param_1) {
        return;
      }
      cVar1 = puVar2[0x175];
      puVar2 = puVar2 + 0x174;
    }
  }
  iVar4 = param_1 << 1;
LAB_8006d6d4:
  iVar4 = (iVar4 + param_1) * 0x7c;
  (&DAT_80113ad2)[iVar4] = 0;
  puVar5 = (undefined4 *)(&DAT_80113c28 + iVar4);
  iVar3 = 6;
  do {
    *puVar5 = 0;
    iVar3 = iVar3 + -1;
    puVar5 = puVar5 + 1;
  } while (iVar3 != 0);
  FUN_8006d5dc(&DAT_80113ad0 + iVar4);
  return;
}
