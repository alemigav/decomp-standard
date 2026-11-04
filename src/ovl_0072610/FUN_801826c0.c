/* FUN_801826c0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801826c0  body 0x801826c0..0x8018277b  size 188 B
 * body sha256 4ace884574f96043c67beb5bca633d8e1420ae9745409398491d37ca7b169120
 * provider record sha256 d482d3a71cc3d7dd104d183cd4e6ad14794469532f4a16497cba8778323a4a99
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801826c0(undefined1 *param_1,undefined1 *param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  iVar2 = 0;
  if (0 < param_4) {
    puVar4 = param_2 + 0xf;
    puVar3 = param_1 + 0xf;
    do {
      *param_2 = *param_1;
      puVar4[-0xe] = puVar3[-0xe];
      puVar4[-0xd] = puVar3[-0xd];
      puVar4[-0xc] = puVar3[-0xc];
      puVar4[-0xb] = puVar3[-0xb];
      puVar4[-10] = puVar3[-10];
      puVar4[-9] = puVar3[-9];
      puVar4[-8] = puVar3[-8];
      puVar4[-7] = puVar3[-7];
      puVar4[-6] = puVar3[-6];
      puVar4[-5] = puVar3[-5];
      puVar4[-4] = puVar3[-4];
      param_1 = param_1 + param_3;
      puVar4[-3] = puVar3[-3];
      iVar2 = iVar2 + 1;
      puVar4[-2] = puVar3[-2];
      param_2 = param_2 + param_3;
      puVar4[-1] = puVar3[-1];
      uVar1 = *puVar3;
      puVar3 = puVar3 + param_3;
      *puVar4 = uVar1;
      puVar4 = puVar4 + param_3;
    } while (iVar2 < param_4);
  }
  return;
}
